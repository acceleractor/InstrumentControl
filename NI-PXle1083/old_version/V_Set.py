import subprocess

exepath = "V_set.exe"

p = subprocess.Popen(exepath, stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True, shell=True)

p.stdin.write('1.12\n')
p.stdin.flush()
