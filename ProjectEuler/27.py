"""
Quadratic primes

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
"""

import math


def is_prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


ans_a = 0
ans_b = 0
max_seq = 0
for a in range(-1000, 1001):
    for b in range(2, 1001):
        if not is_prime(b):
            continue
        n = 0
        while True:
            p = n * n + a * n + b
            if p < 2 or not is_prime(p):
                break
            n = n + 1
        if n > max_seq:
            ans_a = a
            ans_b = b
            max_seq = n

print(ans_a * ans_b)
