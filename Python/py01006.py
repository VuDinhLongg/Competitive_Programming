import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n = int(input())
    while n > 0:
        d = n % 10
        if d != 4 and d != 7:
            print('NO')
            return
        n //= 10
    print('YES')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()