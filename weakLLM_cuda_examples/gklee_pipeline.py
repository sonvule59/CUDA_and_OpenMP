import os
import subprocess
import json
from dotenv import load_dotenv

# load_dotenv()  
dotenv_path = "/home/hungphd/Son/.env"
if not os.path.exists(dotenv_path):
    raise FileNotFoundError(f".env file not found at {dotenv_path}")
load_dotenv(dotenv_path)  # Load .env file explicitly

KLEE_HOME_DIR = os.getenv("KLEE_HOME_DIR")
GKLEE_EXEC = os.getenv("GKLEE_EXEC")

print(f"KLEE_HOME_DIR: {KLEE_HOME_DIR}")
print(f"GKLEE_EXEC: {GKLEE_EXEC}")

if not KLEE_HOME_DIR:
    raise EnvironmentError("KLEE_HOME_DIR is not set! Please define it in the .env file.")
if not GKLEE_EXEC:
    raise EnvironmentError("GKLEE_EXEC is not set! Please define it in the .env file.")
if not os.path.exists(GKLEE_EXEC):
    raise FileNotFoundError(f"GKLEE_EXEC binary not found at {GKLEE_EXEC}")

CUDA_DIR = "HPC_Coder_translated_CUDA"
GKLEE_REPORTS = "gklee_reports"
os.makedirs(GKLEE_REPORTS, exist_ok=True)

def run_gklee_on_file(cuda_file, timeout=120):
    base = os.path.basename(cuda_file)
    report_file = os.path.join(GKLEE_REPORTS, base.replace('.cu', '_gklee.txt'))
    # Pass the current environment to subprocess
    env = os.environ.copy()  # Ensure environment variables are inherited
    cmd = [GKLEE_EXEC, cuda_file]
    try:
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout, env=env)
        with open(report_file, "w") as f:
            f.write(proc.stdout)
            if proc.stderr:
                f.write("\n==== STDERR ====\n")
                f.write(proc.stderr)
        return {"file": cuda_file, "success": proc.returncode == 0, "report": report_file}
    except subprocess.TimeoutExpired:
        with open(report_file, "w") as f:
            f.write("GKLEE analysis timed out\n")
        return {"file": cuda_file, "success": False, "error": "timeout", "report": report_file}

def parse_gklee_report(report_path):
    issues = {"assertion_failures": 0, "race_conditions": 0, "out_of_bounds": 0}
    try:
        with open(report_path) as f:
            for line in f:
                if "assertion failure" in line.lower():
                    issues["assertion_failures"] += 1
                if "race condition" in line.lower():
                    issues["race_conditions"] += 1
                if "out-of-bounds" in line.lower() or "out of bounds" in line.lower():
                    issues["out_of_bounds"] += 1
    except FileNotFoundError:
        print(f"Report file {report_path} not found")
    return issues

def main():
    results = []
    cu_files = [os.path.join(CUDA_DIR, f) for f in os.listdir(CUDA_DIR) if f.endswith('.cu')]
    if not cu_files:
        print(f"No .cu files found in {CUDA_DIR}")
        return
    for cuda_file in cu_files:
        print(f"Analyzing {cuda_file} with GKLEE...")
        result = run_gklee_on_file(cuda_file)
        parsed = parse_gklee_report(result['report'])
        result.update(parsed)
        results.append(result)

    with open("gklee_summary.json", "w") as f:
        json.dump(results, f, indent=2)
    print("GKLEE analysis complete. See gklee_summary.json and gklee_reports/")

if __name__ == "__main__":
    main()