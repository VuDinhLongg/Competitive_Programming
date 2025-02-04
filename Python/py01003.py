import os
import sys
from math import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')



if __name__ == '__main__':
    for it in range(int(input())):
        s = str(input())
        n = len(s)
        a = [0] * n
        for i in range(n):
            a[i] = int(s[i])
        for i in range(n - 1, 0, -1):
            if a[i] >= 5:
                a[i - 1] += 1
            a[i] = 0
        for i in a:
            print(i, end = '')
        print()
