import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n = int(input())
    t = 1e3
    while t > 0 and n % 7:
        m = str(n)
        m = m[::-1]
        m = int(m)
        n += m
    if n % 7 == 0:
        print(n)
    else: print(-1)

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()