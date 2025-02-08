import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def check(n):
    a = str(n)
    if a != a[::-1]: return 0
    if len(a) % 2: return 0
    for i in a:
        if int(i) % 2: return 0
    return 1

def LonggVuz():
    n = int(input())
    for i in range(22, n, 2):
        if check(i): print(i, end = ' ')
    print()

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()