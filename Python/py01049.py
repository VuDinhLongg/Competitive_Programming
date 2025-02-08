import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def nto(n):
    c = int(sqrt(n))
    for i in range(2, c + 1):
        if n % i == 0: return 0
    return n > 1

def LonggVuz():
    n = int(input())
    if not nto(len(str(n))):
        print('NO')
        return
    x, y = 0, 0
    while n > 0:
        if nto(n % 10): x += 1
        else: y += 1
        n //= 10
    print('YES' if x > y else 'NO')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()