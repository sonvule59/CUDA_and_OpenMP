import os
import json
import tempfile
import subprocess
from multiprocessing import Pool, cpu_count
from transformers import AutoTokenizer, AutoModelForCausalLM
import torch
import re

# ----- LOAD MODEL -----
def load_deepseek_model(model_path="deepseek-ai/DeepSeek-R1-Distill-Qwen-1.5B"):
    tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
    model = AutoModelForCausalLM.from_pretrained(
        model_path,
        torch_dtype=torch.float16,
        device_map="auto",
        trust_remote_code=True
    )
    return tokenizer, model

# ----- LOAD FILES -----
def load_cpp_files(folder_path, max_files=100):
    code_examples = []
    count = 0
    for filename in sorted(os.listdir(folder_path)):
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

# ----- CLEAN OUTPUT -----
def clean_translated_code(raw_output):
    blocks = re.findall(r"```[a-zA-Z0-9]*\n(.*?)```", raw_output, re.DOTALL)
    if blocks:
        return blocks[0].strip()
    return raw_output.replace("```", "").strip()

# ----- PROMPT -----
def create_translation_prompt(c_code):
    return (
        "You are a helpful assistant. Translate the following C++ code into valid CUDA. "
        "Return only CUDA `.cu` code, no markdown or explanations.\n\n"
        f"{c_code}\n\nCUDA code:"
    )

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
    return clean_translated_code(full_output[len(prompt):].strip())

# ----- SAVE INDIVIDUAL FILES -----
def save_translated_cuda_files(examples, output_dir="DeepSeekR1"):
    os.makedirs(output_dir, exist_ok=True)
    for ex in examples:
        safe_id = os.path.splitext(ex["id"])[0]
        filename = os.path.join(output_dir, f"{safe_id}.cu")
        with open(filename, "w") as f:
            f.write(ex["translated_code"])

# ----- COMPILE & RUN -----
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

def process_example(args):
    ex, idx, dir_path = args
    code = ex["translated_code"]
    cuda_path = write_cuda_file(code, idx, dir_path)
    result = {
        "id": ex["id"],
        "original_c": ex["c_code"],
        "translated_code": code
    }

    compile_result = compile_cuda_file(cuda_path)
    result.update(compile_result)

    if compile_result["compile_success"]:
        print(f"✅ Compiled: {ex['id']}")
        run_result = run_executable(compile_result["executable"])
        if run_result["run_success"]:
            print(f"🏃 Ran: {ex['id']} → Output:\n{run_result['run_stdout'][:200]}")
        else:
            print(f"🛑 Run failed for: {ex['id']}")
        result.update(run_result)
    else:
        print(f"❌ Compilation failed: {ex['id']}")
        print("---- stderr ----")
        print(compile_result["compile_stderr"][:300])
        result.update({
            "run_stdout": "",
            "run_stderr": "Skipped due to compile error",
            "run_success": False
        })

    return result

# ----- MAIN -----
if __name__ == "__main__":
    folder = "/home/hungphd/Son/weakLLM_cuda_examples/Project_CodeNet_C++1000/p00000"
    print(f"📂 Loading C/C++ files from: {folder}")
    c_examples = load_cpp_files(folder)

    print("🚀 Loading DeepSeek-R1-Distill-Qwen-1.5B...")
    tokenizer, model = load_deepseek_model()

    print("🔁 Translating C++ code to CUDA...")
    translated_examples = []
    for i, ex in enumerate(c_examples):
        print(f"🔹 Translating file: {ex['id']}")
        cuda_code = translate_c_to_cuda(ex["c_code"], tokenizer, model)
        print("🔸 CUDA preview:\n" + "\n".join(cuda_code.splitlines()[:5]) + "\n...")
        translated_examples.append({
            "id": ex["id"],
            "c_code": ex["c_code"],
            "translated_code": cuda_code
        })

    print("📁 Saving CUDA files to folder 'DeepSeekR1'")
    save_translated_cuda_files(translated_examples, output_dir="DeepSeekR1")

    print("⚙️  Compiling and executing...")
    with tempfile.TemporaryDirectory() as tmpdir:
        args = [(ex, i, tmpdir) for i, ex in enumerate(translated_examples)]
        with Pool(processes=max(1, cpu_count() - 1)) as pool:
            final_results = pool.map(process_example, args)

    json_file = "deepseek_r1_results.json"
    print(f"💾 Saving output to '{json_file}'")
    with open(json_file, "w") as f:
        json.dump(final_results, f, indent=2)

    error_file = "deepseek_r1_compile_and_run_errors.txt"
    with open(error_file, "w") as f:
        for result in final_results:
            if not result.get("compile_success", True):
                f.write(f"❌ Compilation failed for: {result['id']}\n")
                f.write("---- Compile stderr ----\n")
                f.write(result["compile_stderr"] + "\n\n")
            elif not result.get("run_success", True):
                f.write(f"🛑 Execution failed for: {result['id']}\n")
                f.write("---- Run stderr ----\n")
                f.write(result["run_stderr"] + "\n\n")

    print(f"📝 Errors saved to '{error_file}'")
    print("✅ Done.")
