import os
import subprocess
import json
import time

CUDA_SOURCE_DIR = "/home/hungphd/Son/weakLLM_cuda_examples/DeepSeekR1"      
CUDA_OUTPUT_DIR = "./cuda_bin"           # Executable output dir
os.makedirs(CUDA_OUTPUT_DIR, exist_ok=True)

results = []
error_lines = []

cu_files = [f for f in os.listdir(CUDA_SOURCE_DIR) if f.endswith(".cu")]

for cu_file in cu_files:
    source_path = os.path.join(CUDA_SOURCE_DIR, cu_file)
    base_name = os.path.splitext(cu_file)[0]
    output_path = os.path.join(CUDA_OUTPUT_DIR, f"{base_name}.out")

    compile_result = subprocess.run(
        ["nvcc", source_path, "-o", output_path],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    compile_success = compile_result.returncode == 0

    entry = {
        "file": cu_file,
        "output": output_path,
        "compile_success": compile_success,
        "compile_stdout": compile_result.stdout,
        "compile_stderr": compile_result.stderr
    }

    if not compile_success:
        error_lines.append(f"❌ Compilation failed: {cu_file}\n")
        error_lines.append(compile_result.stderr + "\n")
        entry.update({
            "run_success": False,
            "run_stdout": "",
            "run_stderr": "Skipped due to compile failure",
            "run_time_seconds": None
        })
    else:
        try:
            start_time = time.time()
            run_result = subprocess.run(
                [output_path],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                timeout=10,
                text=True
            )
            elapsed = time.time() - start_time

            entry.update({
                "run_success": run_result.returncode == 0,
                "run_stdout": run_result.stdout,
                "run_stderr": run_result.stderr,
                "run_time_seconds": round(elapsed, 4)
            })

            if run_result.returncode != 0:
                error_lines.append(f"🛑 Runtime error: {cu_file}\n")
                error_lines.append(run_result.stderr + "\n")

        except subprocess.TimeoutExpired:
            entry.update({
                "run_success": False,
                "run_stdout": "",
                "run_stderr": "Execution timed out",
                "run_time_seconds": None
            })
            error_lines.append(f"⏰ Execution timed out: {cu_file}\n\n")

    results.append(entry)

# Save full JSON log
with open("DeepSeekR1_cuda_compile_log.json", "w") as f:
    json.dump(results, f, indent=2)

# Save error log
with open("DeepSeekR1_cuda_compile_errors.txt", "w") as f:
    f.writelines(error_lines)

print("✅ Compilation & execution complete. Logs saved.")
