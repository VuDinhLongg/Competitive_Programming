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
    n = int(input())
    s = 0
    while n:
        s += n % 10
        n //= 10
    print('YES' if nto(s) else 'NO')