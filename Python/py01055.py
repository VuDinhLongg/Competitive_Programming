import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

for it in range(int(input())):
    a = input()
    if len(a) % 2 == 0:
        print('NO')
        continue
    if a[0] == a[1]:
        print('NO')
        continue
    ok = 1
    for i in range(2, len(a), 2):
        if a[i] != a[0]:
            print('NO')
            ok = 0 
            break
    if ok: print('YES')