import os
import sys
from math import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def nto(n):
    c = int(sqrt(n))
    for i in range(2, c + 1):
        if n % i == 0:
            return 0
    return n > 1

if __name__ == '__main__':
    for it in range(int(input())):
        n = int(input())
        d = 0
        for i in range(1, n):
            if gcd(i, n) == 1:
                d += 1
        if nto(d):
            print('YES')
        else:
            print('NO')
