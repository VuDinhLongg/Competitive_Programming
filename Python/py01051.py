import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

for it in range(int(input())):
    n = int(input())
    s = 0
    while n:
        s += n % 10
        n //= 10
    a = str(s)
    print('YES' if len(a) > 1 and a == a[::-1] else 'NO')