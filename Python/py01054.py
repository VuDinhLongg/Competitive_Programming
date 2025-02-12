import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

for it in range(int(input())):
    n = int(input())
    t = 1
    while n:
        d = n % 10
        if d <= 1:
            n //= 10
            continue
        t *= d
        n //= 10
    print(t)