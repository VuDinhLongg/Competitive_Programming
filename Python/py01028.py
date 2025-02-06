import os
import sys
from math import *
from collections import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')

def LonggVuz():
    a = input()
    for i in a:
        if i != ' ':
            print(i, end = '')
        else: print()

tc = 1
# tc = int(input())
for it in range(tc):
    LonggVuz()