import subprocess

exepath = "v_SET.exe"

p = subprocess.Popen(exepath, stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True, shell=True)


p.stdin.write('1.202\n')
p.stdin.flush()

p.stdin.write('0\n')
p.stdin.flush()

p.stdin.write('PXI1Slot2\n')

p.stdin.flush()
