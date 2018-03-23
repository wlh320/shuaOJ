"""
Integer right triangles

For which value of p ≤ 1000, is the number of solutions maximised?

"""
from collections import Counter
ps = []
""" naive
for a in range(1, 334):
    for b in range(a+1, 1000-334):
        for p in range(1, 1001):
            c = p - a - b
            if c < a or c < b:
                continue
            if c**2 == a**2 + b**2:
                ps.append(p)
"""
""" not so naive
for p in range(1, 1001):
    for a in range(1, 334):
        if (2 * a) >= p:
            continue
        m = p * (p - 2 * a)
        n = 2 * (p - a)
        if m % n == 0:
            b = m // n
            c = p - a - b
            if a < b and b < c:
                ps.append(p)
"""
from fractions import gcd
from math import sqrt
for m in range(2, int(sqrt(1000 / 2))):
    for n in range(1, m):
        if gcd(m, n) == 1 and (m - n) % 2:  # No Duplicates
            for k in range(2 * m * (m + n), 1000, 2 * m * (m + n)):
                ps.append(k)

c = Counter(ps)
print(c.most_common(1)[0][0])
