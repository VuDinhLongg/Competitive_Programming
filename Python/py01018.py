import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

p = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ_.'

def LonggVuz():
    a = input()
    while a != "0":
        k, s = a.split()
        k = int(k)
        if k == 0:
            return
        n = len(s)
        res = ""
        for i in range(n):
            j = 0
            while j < len(p) and p[j] != s[i]:
                j += 1
            res += str(p[(j + k) % 28])
        print(res[::-1])
        a = input()

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()