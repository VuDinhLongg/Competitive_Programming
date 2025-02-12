import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

for it in range(int(input())):
    a = input()
    n = len(a)
    s, t = 0, 1
    ok = 0
    for i in range(n):
        if i % 2 == 0:
            s += int(a[i])
        else:
            if int(a[i]) > 0:
                t *= int(a[i])
                ok = 1
    if ok: print(s, t)
    else: print(s, 0)