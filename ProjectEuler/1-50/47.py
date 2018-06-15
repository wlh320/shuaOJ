"""
Distinct primes factors

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
"""
from pe_utils import sieve

p = sieve(1000000)


def num_pfactors(n):
    cnt = 0
    if p[n]:
        return 0
    x = n
    i = 2
    while x != 1:
        if not p[i]:
            i += 1
            continue
        if x % i == 0:
            cnt += 1
        while x % i == 0:
            x //= i
        i += 1
    return cnt


nf = dict()
for i in range(647, 1000000):
    if num_pfactors(i) != 4:
        continue
    nf[i] = 4
    if i - 1 in nf and i - 2 in nf and i - 3 in nf:
        print(i - 3)
        break
