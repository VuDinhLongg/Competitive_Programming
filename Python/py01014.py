import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a, k, n = map(int, input().split())
    ok = 0
    mx = n - a
    i = k - a % k
    if i > mx:
        print(-1)
        return
    while i <= mx:
        print(i, end = ' ')
        i += k

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()