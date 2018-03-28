"""
Pentagon numbers

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?
"""

import sys
import math


def penta(n):
    return n * (3 * n - 1) // 2


def check(n):
    root = int((1 + math.sqrt(1+24*n))/6)
    if penta(root) == n:
        return True
    return False


for a in range(2, 5000):
    for b in range(1, a):
        pa, pb = penta(a), penta(b)
        s, d = pa + pb, pa - pb
        if check(s) and check(d):
            print(d)
            sys.exit(0)  # just find first is ok!
