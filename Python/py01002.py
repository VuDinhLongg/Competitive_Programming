import os
import sys
from math import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

if __name__ == '__main__':
    s = str(input())
    a = int(s[0])
    b = int(s[4])
    c = int(s[8])
    if a + b == c:
        print('YES')
    else:
        print('NO')