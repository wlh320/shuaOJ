"""
Prime permutations
like 1487, 4817, 8147
What 12-digit number do you form by concatenating the three terms in this sequence?
"""
import math
import sys


def sieve(n):
    prime = [True] * (n+1)
    for i in range(2, int(math.sqrt(n))+1):
        if prime[i]:
            for j in range(i * i, 10000, i):
                prime[j] = False
    return prime


P = sieve(10000)


def is_prime(n):
    assert n < 10000
    return P[n]


def check(a, b, c):
    if not is_prime(b) or not is_prime(c):
        return False
    a, b, c = map(lambda x: sorted(str(x)), (a, b, c))
    return a == b and b == c


for a in range(1000, 9999):
    if not is_prime(a):
        continue
    for d in range(1000, (10000 - a) // 2 + 1):
        b, c = a + d, a + 2 * d
        if check(a, b, c) and a != 1487:
            print(str(a) + str(b) + str(c))
            sys.exit(0)
