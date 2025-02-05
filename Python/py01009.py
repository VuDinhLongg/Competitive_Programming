import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a = input()
    h, t = 0, 0
    for i in a:
        if 'a' <= i and i <= 'z':
            t += 1
        else: h += 1
    if t >= h:
        a = a.lower()
    else:
        a = a.upper()
    print(a)

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()