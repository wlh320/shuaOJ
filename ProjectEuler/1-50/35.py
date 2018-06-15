"""
Circular primes

How many circular primes are there below one million?
"""
import math


def sieve(n):
    A = [True] * n
    for i in range(2, int(math.sqrt(n))):
        if A[i] == True:
            for j in range(i * i, n, i):
                A[j] = False
    return A


primes = sieve(1000000)
result = 0
for i in range(2, 1000000):
    if primes[i] is False:
        continue
    s = str(i)
    rots = [s[i:] + s[0:i] for i in range(len(s))]
    yes = True
    for rot in rots:
        rot = int(rot)
        if primes[rot] is False:
            yes = False
    if yes:
        result += 1
print(result)
