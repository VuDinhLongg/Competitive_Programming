import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def check(n):
    s = str(n)
    if(s != s[::-1]): return 0
    for i in s:
        if i not in '02468':
            return 0
    return len(s) % 2 == 0

def LonggVuz():
    n = int(input())
    for i in range(22, n):
        if check(i):
            print(i, end = ' ')
    print()

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()