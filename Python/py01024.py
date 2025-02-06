import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def check(n):
    s = str(n)
    t = 0
    while n > 0:
        t += n % 10
        n //= 10
    if t % 10:
        return 0
    for i in range(len(s) - 1):
        if abs(ord(s[i]) - ord(s[i + 1])) != 2:
            return 0
    return 1

def LonggVuz():
    n = int(input())
    if check(n):
        print('YES')
    else: print('NO')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()