import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a = input()
    n = len(a)
    if n < 3:
        print('NO')
        return
    i = 0
    while i < n - 1 and a[i] < a[i + 1]: i += 1
    while i < n - 1 and a[i] > a[i + 1]: i += 1
    if i == n - 1: print('YES')
    else: print('NO')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()