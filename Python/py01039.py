import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n = int(input())
    d = [0] * 10
    a = str(n)
    cnt = 0
    while n > 0:
        d[n % 10] += 1
        if d[n % 10] == 1: cnt += 1
        if cnt == 3:
            print('NO')
            return
        n //= 10
    n = len(a)
    for i in range(n - 2):
        if a[i] != a[i + 2]:
            print('NO')
            return
    print('YES')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()