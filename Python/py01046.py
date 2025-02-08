import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def run(n, a, c, b):
    if n == 1:
        print(a, c, sep = ' -> ')
        return
    run(n - 1, a, b, c)
    print(a, c, sep = ' -> ')
    run(n - 1, b, c, a)

def LonggVuz():
    n = int(input())
    run(n, 'A', 'C', 'B')

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()