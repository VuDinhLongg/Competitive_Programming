import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    n = int(input())
    print('1 * ', end = '')
    c = int(sqrt(n))
    for i in range(2, c + 1):
        if n % i == 0:
            d = 0
            while n % i == 0:
                d += 1
                n //= i
            print(i, d, sep = '^', end = '')
            if n > 1:
                print(' * ', end = '')
    if n > 1:
        print(n, 1, sep = '^', end = '')
    print()

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()