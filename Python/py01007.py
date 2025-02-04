import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n, x, m = map(float, input().split())
    x = 1.0 + x / 100.0
    res = 0
    while n < m:
        n *= x
        res += 1
    print(res)

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()