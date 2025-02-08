import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def run(s, n, a, b, c):
    if len(s) == n:
        if a > 0 and a <= b and b <= c:
            print(s)
        return
    run(s + 'A', n, a + 1, b, c)
    run(s + 'B', n, a, b + 1, c)
    run(s + 'C', n, a, b, c + 1)

def LonggVuz():
    n = int(input())
    for i in range(3, n + 1):
        run('', i, 0, 0, 0)
    print()

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()