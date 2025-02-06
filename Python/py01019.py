import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a = input()
    b = a[::-1]
    n = len(a)
    for i in range(1, n):
        if abs(ord(a[i]) - ord(a[i - 1])) != abs(ord(b[i]) - ord(b[i - 1])):
            print('NO')
            return
    print('YES')

tc = 1
tc = int(input())
for it in range(tc):
    LonggVuz()