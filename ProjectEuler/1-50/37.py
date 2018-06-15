"""
Truncatable primes
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
"""
from math import sqrt


def sieve(n):
    flags = [True] * n
    for i in range(2, int(sqrt(n))):
        if flags[i] is True:
            for j in range(i * i, n, i):
                flags[j] = False
    return flags


primes = sieve(1000000)
primes[0] = primes[1] = False
i = 0
n = 11
result = 0
while i < 11:
    while not primes[n]:
        n += 1
    s = str(n)
    rots = [int(s[i:]) for i in range(len(s))]
    rots.extend([int(s[:i]) for i in range(1, len(s))])
    yes = True
    for rot in rots:
        if not primes[rot]:
            yes = False
            break
    if yes:
        i += 1
        # print(n, rots)
        result += n
    n += 1

print(result)
