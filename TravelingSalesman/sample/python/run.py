import subprocess
from subprocess import PIPE

TESTER  = "../../build/libs/Tester.jar"
COMMAND = "python3 main.py"
OPTIONS = ""
TESTNUM = 10

for i in range(TESTNUM):
    RUN_CMD = 'java -jar {} --exec "{}" --seed {} {}'.format(TESTER, COMMAND, i + 1, OPTIONS)
    proc = subprocess.run(RUN_CMD, shell=True, stdout=PIPE, stderr=PIPE)
    print(proc.stderr.decode('utf-8'), end='')
    print(proc.stdout.decode('utf-8'), end='')
