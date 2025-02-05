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
        if n % i == 0:
            return 0
    return n > 1

def LonggVuz():
    a, b = map(int, input().split())
    c = gcd(a, b)
    s = 0
    while c > 0:
        s += c % 10
        c //= 10
    if nto(s):
        print('YES')
    else: print('NO')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()