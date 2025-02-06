import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    l, r = map(int, input().split())
    for i in range(l, r):
        for j in range(i + 1, r):
            for k in range(j + 1, r + 1):
                if gcd(i, j) == 1 and gcd(j, k) == 1 and gcd(i, k) == 1:
                    print('(', end = '')
                    print(i, j, k, sep = ', ', end = ')\n')
    print()

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()