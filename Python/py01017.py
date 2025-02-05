import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a = input()
    n = len(a)
    i = 1
    while i <= n:
        d = 1
        while i < n and a[i] == a[i - 1]:
            d += 1
            i += 1
        print(d, end = '')
        print(a[i - 1], end = '')
        i += 1
    print()

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()