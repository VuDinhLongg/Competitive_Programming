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
    for i in range(n):
        if 'A' <= a[i] and a[i] <= 'Z':
            t = int(a[i + 1])
            while t > 0:
                print(a[i], end = '')
                t -= 1
    print()

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()