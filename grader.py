import subprocess
import sys
_, filename, num = sys.argv
for i in range(1, int(num)+1):
    result = subprocess.run(
        f"python {filename} < testcases/{i:02d}.in", shell=True, stdout=subprocess.PIPE)
    output = result.stdout.decode('utf-8').strip()
    actual = open(f"testcases/{i:02d}.out").read().strip()
    print("Testcase", i, ":", "pass" if output.split()
          == actual.split() else "fail")
    if output.split() != actual.split():
        print("Expected:\n", actual, sep="")
        print("Output:\n", output, sep="")
