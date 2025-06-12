import os
import json
from transformers import AutoTokenizer, AutoModelForCausalLM
import torch
import re
from dotenv import load_dotenv

load_dotenv()

INPUT_FILES = os.getenv("INPUT_FOLDER_PATH")
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
def create_cuda_prompt(code, language):
    lang_text = "C++" if language == "cpp" else "C"
    prompt = (
        f"You are an expert in translating {lang_text} code to CUDA. "
        f"Translate the following code to CUDA to parallelize compute-heavy parts using GPU. "
        f"Return only valid CUDA code without markdown or explanation.\n\n"
        f"{code}\n\nCUDA code:"
    )
    return prompt[:14000]  # trim if too long

# ----- CLEAN OUTPUT -----
def clean_translated_code(raw_output):
    blocks = re.findall(r"```[a-zA-Z0-9]*\n(.*?)```", raw_output, re.DOTALL)
    if blocks:
        return blocks[0].strip()
    return raw_output.replace("```", "").strip()

# ----- TRANSLATION -----
def translate_code_to_cuda(code, language, tokenizer, model):
    prompt = create_cuda_prompt(code, language)
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
def save_cuda_files(examples, output_dir="hpc_coder_cuda_translated"):
    os.makedirs(output_dir, exist_ok=True)
    for ex in examples:
        base = os.path.splitext(ex["id"])[0]
        ext = ".cu"
        filename = os.path.join(output_dir, f"{base}{ext}")
        with open(filename, "w") as f:
            f.write(ex["translated_code"])

# ----- MAIN -----
if __name__ == "__main__":
    print(f"📂 Loading files from: {INPUT_FILES}")
    code_examples = load_code_files(INPUT_FILES)

    print("🚀 Loading HPC Coder model...")
    tokenizer, model = load_model("hpcgroup/hpc-coder-v2-1.3b")

    print("🔁 Translating to CUDA...")
    translated_examples = []
    for i, ex in enumerate(code_examples):
        print(f"🔹 Translating {ex['id']}")
        cuda_code = translate_code_to_cuda(ex["code"], ex["language"], tokenizer, model)
        print("🔸 CUDA preview:", "\n".join(cuda_code.splitlines()[:5]), "\n...")
        translated_examples.append({
            "id": ex["id"],
            "language": ex["language"],
            "code": ex["code"],
            "translated_code": cuda_code
        })

    save_cuda_files(translated_examples)

    json_file = "hpcCoder_cuda_translation_result_v2.json"
    print(f"💾 Saving output to '{json_file}'")
    with open(json_file, "w") as f:
        json.dump(translated_examples, f, indent=2)

    print("✅ CUDA translation complete.")
