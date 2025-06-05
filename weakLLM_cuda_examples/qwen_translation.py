import os
import json
import tempfile
import subprocess
from multiprocessing import Pool, cpu_count

from transformers import AutoTokenizer, AutoModelForCausalLM
import torch

# ----- 1. LOAD QWEN MODEL -----
def load_qwen_model(model_path="Qwen/Qwen3-0.6B"):
    tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
    model = AutoModelForCausalLM.from_pretrained(
        model_path,
        torch_dtype=torch.float16,
        device_map="auto",
        trust_remote_code=True
    )
    return tokenizer, model

NUM_MAX_FILES = 100
# ----- 2. LOAD ALL .cpp/.c FILES FROM A FOLDER -----
def load_cpp_files(folder_path, max_files=NUM_MAX_FILES):  
    code_examples = []
    count = 0
    for filename in os.listdir(folder_path):
        if filename.endswith(".cpp") or filename.endswith(".c"):
            full_path = os.path.join(folder_path, filename)
            with open(full_path, "r") as f:
                code = f.read()
                code_examples.append({
                    "id": filename,
                    "c_code": code
                })
            count += 1
            if count >= max_files:
                break
    return code_examples

# ----- 3. CREATE PROMPT AND TRANSLATE -----
def create_translation_prompt(c_code):
    return f"""Translate the following C++ code into CUDA:\n\n```c++\n{c_code}\n```\n\nTranslated CUDA code:"""

def translate_c_to_cuda(c_code, tokenizer, model, max_tokens=512):
    prompt = create_translation_prompt(c_code)
    inputs = tokenizer(prompt, return_tensors="pt").to(model.device)

    outputs = model.generate(
        **inputs,
        max_new_tokens=max_tokens,
        temperature=0.7,
        top_p=0.9,
        do_sample=False,
        pad_token_id=tokenizer.eos_token_id
    )

    full_output = tokenizer.decode(outputs[0], skip_special_tokens=True)
    return full_output[len(prompt):].strip()

# ----- 4. FILE I/O AND COMPILATION -----
def write_cuda_file(code: str, file_id: int, dir_path: str):
    filename = os.path.join(dir_path, f"program_{file_id}.cu")
    with open(filename, "w") as f:
        f.write(code)
    return filename

def compile_cuda_file(cuda_file_path: str):
    exe_path = cuda_file_path.replace(".cu", "")
    try:
        result = subprocess.run(
            ["nvcc", cuda_file_path, "-o", exe_path],
            capture_output=True,
            text=True,
            timeout=10
        )
        return {
            "source": cuda_file_path,
            "executable": exe_path,
            "compile_stdout": result.stdout.strip(),
            "compile_stderr": result.stderr.strip(),
            "compile_success": result.returncode == 0
        }
    except subprocess.TimeoutExpired:
        return {
            "source": cuda_file_path,
            "executable": None,
            "compile_stdout": "",
            "compile_stderr": "Timeout",
            "compile_success": False
        }

def run_executable(exe_path: str):
    try:
        result = subprocess.run(
            [exe_path],
            capture_output=True,
            text=True,
            timeout=5
        )
        return {
            "run_stdout": result.stdout.strip(),
            "run_stderr": result.stderr.strip(),
            "run_success": result.returncode == 0
        }
    except subprocess.TimeoutExpired:
        return {
            "run_stdout": "",
            "run_stderr": "Timeout",
            "run_success": False
        }

# ----- 5. PIPELINE FOR EACH EXAMPLE -----
def process_example(args):
    ex, idx, dir_path = args
    code = ex["translated_code"]
    cuda_path = write_cuda_file(code, idx, dir_path)
    result = {"id": ex["id"], "original_c": ex["c_code"], "translated_code": code}

    compile_result = compile_cuda_file(cuda_path)
    result.update(compile_result)

    if compile_result["compile_success"]:
        run_result = run_executable(compile_result["executable"])
        result.update(run_result)
    else:
        result.update({
            "run_stdout": "",
            "run_stderr": "Skipped due to compile error",
            "run_success": False
        })

    return result

# ----- 6. MAIN DRIVER -----
if __name__ == "__main__":
    folder = "/home/hungphd/Son/weakLLM_cuda_examples/Project_CodeNet_C++1000/p00000" 

    print(f"Loading C++ files from '{folder}'...")
    c_examples = load_cpp_files(folder, max_files= NUM_MAX_FILES)

    print("Loading Qwen model...")
    tokenizer, model = load_qwen_model()

    print("🔁 Translating C++ to CUDA...")
    translated_examples = []
    for ex in c_examples:
        cuda_code = translate_c_to_cuda(ex["c_code"], tokenizer, model)
        translated_examples.append({
            "id": ex["id"],
            "c_code": ex["c_code"],
            "translated_code": cuda_code
        })

    print("⚙️  Compiling and running all CUDA programs...")
    with tempfile.TemporaryDirectory() as tmpdir:
        args = [(ex, i, tmpdir) for i, ex in enumerate(translated_examples)]
        with Pool(processes=max(1, cpu_count() - 1)) as pool:
            final_results = pool.map(process_example, args)

    print("💾 Saving output...")
    with open("final_cuda_pipeline_results.json", "w") as f:
        json.dump(final_results, f, indent=2)

    print("✅ Pipeline complete! Output saved to 'final_cuda_pipeline_results.json'")
