"""
Diophantine equation
x^2 – Dy^2 = 1
Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

tip: 用连分数解佩尔方程-Pell's equation
"""
import math


def is_square(n):
    r = int(math.sqrt(n))
    return n == r*r


def solve(d):
    """p/q 是 sqrt(d) 的连分数表示"""
    a0 = int(math.sqrt(d))
    g = q2 = p1 = 0
    h = q1 = p2 = 1
    a = a0
    while True:
        g = a * h - g
        h = int((d - g*g) / h)
        p = a * p2 + p1
        q = a * q2 + q1
        a = int((g + a0) / h)
        if p * p - d * q * q == 1:
            break
        p1 = p2
        p2 = p
        q1 = q2
        q2 = q
    return p


max_x = -1
max_d = -1
for d in range(1, 1001):
    if is_square(d):
        continue
    x = solve(d)
    if x > max_x:
        max_x = x
        max_d = d
print(max_d)
