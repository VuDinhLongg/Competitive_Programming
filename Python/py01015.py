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
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            print('NO')
            return
    print('YES')

tc = int(input())
for it in range(tc):
    LonggVuz()