import os
import json
import re
from transformers import AutoTokenizer, AutoModelForCausalLM
import torch
from dotenv import load_dotenv

load_dotenv()

INPUT_FILES = os.getenv('INPUT_FOLDER_PATH')
os.environ["PYTORCH_CUDA_ALLOC_CONF"] = "expandable_segments:True"

# ----- LOAD MODEL -----
def load_model(model_path):
    tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
    model = AutoModelForCausalLM.from_pretrained(
        model_path,
        torch_dtype=torch.float16,
        device_map="auto",
        trust_remote_code=True
    )
    return tokenizer, model

# ----- LOAD FILES -----
def load_code_files(folder_path, max_files=5):
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
def create_openmp_prompt(code, language, reasoning_mode=False):
    lang_text = "C++" if language == "cpp" else "C"
    if reasoning_mode:
        instruction = (
            f"You are a helpful AI that reasons step-by-step to translate {lang_text} code to OpenMP. "
            "Analyze the code first, identify parallelizable components, then generate the OpenMP version. Output only code.\n\n"
        )
    else:
        instruction = (
            f"You are an expert in code translation from {lang_text} to OpenMP. Translate the following code to use OpenMP for parallelization. "
            "Focus on parallel loops or sections. Output valid code only with no markdown or explanation.\n\n"
        )

    max_code_length = 14000
    if len(code) > max_code_length:
        code = code[:max_code_length]

    return instruction + code + "\n\nOpenMP code:"

# ----- CLEAN OUTPUT -----
def clean_translated_code(raw_output):
    blocks = re.findall(r"```[a-zA-Z0-9]*\n(.*?)```", raw_output, re.DOTALL)
    if blocks:
        return blocks[0].strip()
    return raw_output.replace("```", "").strip()

# ----- TRANSLATION -----
def translate_code_to_openmp(code, language, tokenizer, model, reasoning_mode=False):
    prompt = create_openmp_prompt(code, language, reasoning_mode)
    inputs = tokenizer(prompt, return_tensors="pt").to(model.device)
    outputs = model.generate(
        **inputs,
        max_new_tokens=2048,
        temperature=0.0,
        top_p=0.9,
        do_sample=False,
        pad_token_id=tokenizer.eos_token_id
    )
    full_output = tokenizer.decode(outputs[0], skip_special_tokens=True)
    torch.cuda.empty_cache()
    return clean_translated_code(full_output[len(prompt):].strip())

# ----- SAVE FILES -----
def save_openmp_files(examples, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    for ex in examples:
        base = os.path.splitext(ex["id"])[0]
        ext = ".cpp" if ex["language"] == "cpp" else ".c"
        filename = os.path.join(output_dir, f"{base}_omp{ext}")
        with open(filename, "w") as f:
            f.write(ex["translated_code"])

# ----- MAIN -----
if __name__ == "__main__":
    for mode_name, reasoning in [("no_reasoning", False), ("with_reasoning", True)]:
        print(f"===== Starting {mode_name.replace('_', ' ').title()} Mode =====")

        folder = INPUT_FILES
        print(f"📂 Loading files from: {folder}")
        code_examples = load_code_files(folder)

        print("🚀 Loading model...")
        tokenizer, model = load_model("nvidia/Llama-3.1-Nemotron-Nano-4B-v1.1")

        print("🔁 Translating to OpenMP...")
        translated_examples = []
        for i, ex in enumerate(code_examples):
            print(f"🔹 Translating {ex['id']}")
            omp_code = translate_code_to_openmp(ex["code"], ex["language"], tokenizer, model, reasoning_mode=reasoning)
            print("🔸 OpenMP preview:", "\n".join(omp_code.splitlines()[:5]), "\n...")
            translated_examples.append({
                "id": ex["id"],
                "language": ex["language"],
                "code": ex["code"],
                "translated_code": omp_code
            })

        save_dir = f"nemotron_{mode_name}_translated"
        save_openmp_files(translated_examples, output_dir=save_dir)

        json_file = f"nemotron_{mode_name}_results_only_translation.json"
        print(f"💾 Saving output to '{json_file}'")
        with open(json_file, "w") as f:
            json.dump(translated_examples, f, indent=2)

        print(f"✅ Finished {mode_name.replace('_', ' ').title()} Mode\n")
