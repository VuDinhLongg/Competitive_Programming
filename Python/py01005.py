import os
import sys
from math import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')



if __name__ == '__main__':
    a = int(input())
    f, s = 0, 0
    while a > 0:
        d = a % 10
        if d == 4:
            f += 1
        if d == 7:
            s += 1
        a //= 10
    if f + s == 4 or f + s == 7:
        print('YES')
    else:
        print('NO')