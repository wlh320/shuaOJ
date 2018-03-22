"""
Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
"""

import math


def sieve(n):
    A = [True] * n
    for i in range(2, int(math.sqrt(n))):
        if A[i] == True:
            for j in range(i*i, n, i):
                A[j] = False
    return [i for i in range(2, n) if A[i] == True]


print(sum(sieve(2000000)))
