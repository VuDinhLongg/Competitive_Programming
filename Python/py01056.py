import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def nto(n):
    c = int(sqrt(n))
    for i in range(2, c + 1):
        if n % i == 0: return 0
    return n > 1

for it in range(int(input())):
    a = input()
    n = len(a)
    s = 0
    ok = 1
    for i in range(n):
        s += int(a[i])
        if i % 2:
            if int(a[i]) % 2 == 0:
                ok = 0; break
        else:
            if int(a[i]) % 2 == 1:
                ok = 0; break
    print('YES' if ok and nto(s) else 'NO')
            