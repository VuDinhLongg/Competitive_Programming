import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n, k = map(int, input().split())
    st, en = 10**(k - 1), 10**k
    d = 0
    for i in range(st, en):
        if gcd(i, n) == 1:
            print(i, end = ' ')
            d += 1
            if d == 10:
                print()
                d = 0
    print()

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()