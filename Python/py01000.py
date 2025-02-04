import os
import sys
from math import *

if os.path.exists('Accepted.py'):
    sys.stdin = open('icpc.inp', 'r')
    sys.stdout = open('icpc.out', 'w')



if __name__ == '__main__':
    a = str(input())
    print('Hello', a + str('!'))