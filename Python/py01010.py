import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a = input()
    if a[0] == a[-2] and a[1] == a[-1]:
        print('YES')
    else: print('NO')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()