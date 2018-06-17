"""
Concealed Square
Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
"""
import math
import re


def is_square(n):
    r = int(math.sqrt(n))
    return r * r == n


LOW = int(math.sqrt(1020304050607080900)) // 100
HIG = int(math.sqrt(1929394959697989990)) // 100
PTN = re.compile(r'^1\d2\d3\d4\d5\d6\d7\d8\d9\d0')

for i in range(LOW, HIG, 1):
    for ch in ['30', '70']:
        n = str(i) + ch
        n = int(n)
        x = str(n * n)
        if re.match(PTN, x):
            print(n)
            break
