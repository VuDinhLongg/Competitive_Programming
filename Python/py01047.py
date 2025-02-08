import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n = int(input())
    s = ''
    for i in range(4):
        s = str(n % 10) + s;
        n //= 10
    s = int(s)
    c = int(sqrt(s))
    for i in range(2, c + 1):
        if s % i == 0:
            print('NO')
            return
    print('YES' if s > 1 else 'NO')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()