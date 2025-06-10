import os
import json
import tempfile
import subprocess
from multiprocessing import Pool, cpu_count
from transformers import AutoTokenizer, AutoModelForCausalLM
import torch
import re
import os
from dotenv import load_dotenv

load_dotenv()

INPUT_FILES = os.getenv('INPUT_FOLDER_PATH')
# ----- LOAD MODEL -----
def load_model(model_path="hpcgroup/hpc-coder-v2-1.3b"):
    tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
    model = AutoModelForCausalLM.from_pretrained(
        model_path,
        torch_dtype=torch.float16,
        device_map="auto",
        trust_remote_code=True
    )
    return tokenizer, model

# ----- LOAD FILES -----
def load_code_files(folder_path, max_files=50):
    code_examples = []
    count = 0
    for filename in sorted(os.listdir(folder_path)):
        if filename.endswith(".cpp") or filename.endswith(".c"):
            full_path = os.path.join(folder_path, filename)
            with open(full_path, "r") as f:
                code = f.read()
                code_examples.append({
                    "id": filename,
                    "language": "cpp" if filename.endswith(".cpp") else "c",
                    "code": code
                })
            count += 1
            if count >= max_files:
                break
    return code_examples

# ----- PROMPT CREATION -----
def create_openmp_prompt(code, language):
    lang_text = "C++" if language == "cpp" else "C"
    return (
        f"You are an expert in code translation from C++ to OpenMP. Translate the following C++ code to use OpenMP for parallelization. "
        "Focus on parallel loops or sections. Please return a **complete and compilable** C++ program with a `main()` function. Output valid code only with no markdown or explanation.\n\n"
        f"{code}\n\nOpenMP code:"
    )

def create_fix_prompt(original_code, broken_code, error_text):
    return (
        "You translated this C/C++ code into OpenMP-parallelized code, but it failed to compile.\n"
        "Here is the original code:\n"
        f"{original_code}\n\n"
        "Here is the broken OpenMP code that failed:\n"
        f"{broken_code}\n\n"
        "Here is the compiler error:\n"
        f"{error_text}\n\n"
        "Please fix the OpenMP code so that it compiles. Return only valid code with no markdown or explanation."
    )

# ----- CLEAN OUTPUT -----
def clean_translated_code(raw_output):
    blocks = re.findall(r"```[a-zA-Z0-9]*\n(.*?)```", raw_output, re.DOTALL)
    if blocks:
        return blocks[0].strip()
    return raw_output.replace("```", "").strip()

# ----- TRANSLATION -----
def translate_code_to_openmp(code, language, tokenizer, model):
    prompt = create_openmp_prompt(code, language)
    inputs = tokenizer(prompt, return_tensors="pt").to(model.device)
    outputs = model.generate(
        **inputs,
        max_new_tokens=2048,
        temperature=0.0,
        top_p=0.9,
        do_sample=False,
        pad_token_id=tokenizer.eos_token_id
    )
    torch.cuda.empty_cache()
    full_output = tokenizer.decode(outputs[0], skip_special_tokens=True)
    return clean_translated_code(full_output[len(prompt):].strip())

def refine_code(original_code, broken_code, error_msg, tokenizer, model):
    prompt = create_fix_prompt(original_code, broken_code, error_msg)
    inputs = tokenizer(prompt, return_tensors="pt").to(model.device)
    outputs = model.generate(
        **inputs,
        max_new_tokens=2048,
        temperature=0.0,
        top_p=0.9,
        do_sample=False,
        pad_token_id=tokenizer.eos_token_id
    )
    torch.cuda.empty_cache()
    full_output = tokenizer.decode(outputs[0], skip_special_tokens=True)
    return clean_translated_code(full_output[len(prompt):].strip())

# ----- SAVE FILES -----
def save_openmp_files(examples, output_dir="hpc_coder_OpenMP_Translated_p00001"):
    os.makedirs(output_dir, exist_ok=True)
    for ex in examples:
        base = os.path.splitext(ex["id"])[0]
        ext = ".cpp" if ex["language"] == "cpp" else ".c"
        filename = os.path.join(output_dir, f"{base}_omp{ext}")
        with open(filename, "w") as f:
            f.write(ex["translated_code"])

# ----- COMPILE & RUN -----
def write_code_file(code: str, file_id: int, language: str, dir_path: str):
    ext = ".cpp" if language == "cpp" else ".c"
    filename = os.path.join(dir_path, f"program_{file_id}{ext}")
    with open(filename, "w") as f:
        f.write(code)
    return filename

def compile_code_file(code_path: str, language: str):
    exe_path = code_path.rsplit(".", 1)[0]
    compiler = "g++" if language == "cpp" else "gcc"
    try:
        result = subprocess.run(
            [compiler, "-fopenmp", code_path, "-o", exe_path],
            capture_output=True,
            text=True,
            timeout=15
        )
        return {
            "source": code_path,
            "executable": exe_path,
            "compile_stdout": result.stdout.strip(),
            "compile_stderr": result.stderr.strip(),
            "compile_success": result.returncode == 0
        }
    except subprocess.TimeoutExpired:
        return {
            "source": code_path,
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
            timeout=15
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
    ex, idx, dir_path, tokenizer, model = args
    code = ex["translated_code"]
    code_path = write_code_file(code, idx, ex["language"], dir_path)
    result = {
        "id": ex["id"],
        "original_code": ex["code"],
        "translated_code": code,
        "refined": False
    }

    compile_result = compile_code_file(code_path, ex["language"])
    result.update(compile_result)

    if not compile_result["compile_success"]:
        refined_code = refine_code(ex["code"], code, compile_result["compile_stderr"], tokenizer, model)
        persistent_refined_dir = "refined_hpc_openmp_code"
        os.makedirs(persistent_refined_dir, exist_ok=True)
        refined_path = write_code_file(refined_code, f"{idx}_refined", ex["language"], persistent_refined_dir)

        # refined_path = write_code_file(refined_code, f"{idx}_refined", ex["language"], dir_path)
        refined_result = compile_code_file(refined_path, ex["language"])
        result["refined"] = True
        result["translated_code"] = refined_code
        result.update(refined_result)
        if refined_result["compile_success"]:
            run_result = run_executable(refined_result["executable"])
            result.update(run_result)
        else:
            result.update({
                "run_stdout": "",
                "run_stderr": "Skipped due to compile error",
                "run_success": False
            })
    else:
        run_result = run_executable(compile_result["executable"])
        result.update(run_result)

    return result

# ----- MAIN -----
if __name__ == "__main__":
    #Set multiprocessing to use 'spawn' to avoid CUDA re-initialization error
    import multiprocessing as mp
    mp.set_start_method("spawn", force=True)

    # folder = INPUT_FILES
    folder = "/home/hungphd/Son/weakLLM_cuda_examples/Project_CodeNet_C++1000/p00001"
    print(f"📂 Loading files from: {folder}")
    code_examples = load_code_files(folder)

    print("🚀 Loading model...")
    tokenizer, model = load_model()

    print("🔁 Translating to OpenMP...")
    translated_examples = []
    for i, ex in enumerate(code_examples):
        print(f"🔹 Translating {ex['id']}")
        omp_code = translate_code_to_openmp(ex["code"], ex["language"], tokenizer, model)
        print("🔸 OpenMP preview:", "\n".join(omp_code.splitlines()[:5]), "\n...")
        translated_examples.append({
            "id": ex["id"],
            "language": ex["language"],
            "code": ex["code"],
            "translated_code": omp_code
        })

    save_openmp_files(translated_examples)

    print("⚙️  Compiling and running...")
    with tempfile.TemporaryDirectory() as tmpdir:
        args = [(ex, i, tmpdir, tokenizer, model) for i, ex in enumerate(translated_examples)]
        # with Pool(processes=max(1, cpu_count() - 1)) as pool:
        #     final_results = pool.map(process_example, args)

    # # 🧵 Serial execution (commented out multiprocessing)
        final_results = []
        for arg in args:
            result = process_example(arg)
            final_results.append(result)

    json_file = "hpcCoder_openmp_results_with_refinement.json"
    print(f"💾 Saving output to '{json_file}'")
    with open(json_file, "w") as f:
        json.dump(final_results, f, indent=2)

    error_file = "hpcCoder_openmp_compile_and_run_errors_with_refinement.txt"
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
