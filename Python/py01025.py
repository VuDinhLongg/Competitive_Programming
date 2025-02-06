import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a = input()
    s = ''
    d = 0
    for i in range(len(a) - 1, -1, -1):
        s += str(a[i])
        d += 1
        if d == 3 and i:
            s += ','
            d = 0
    print(s[::-1])

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()