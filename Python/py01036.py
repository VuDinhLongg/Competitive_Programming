import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n = int(input())
    if n % 2 == 0:
        res = 0.0
        for i in range(2, n + 1, 2):
            res += 1.0 / i
        print('%.6f' % res)
    else:
        res = 0.0
        for i in range(1, n + 1, 2):
            res += 1.0 / i
        print('%.6f' % res)

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()