import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n = int(input())
    m = str(n);
    m = m[::-1]
    m = int(m)
    if gcd(n, m) == 1: print('YES')
    else: print('NO')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()