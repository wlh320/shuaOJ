"""
Consecutive prime sum
Which prime, below one-million, can be written as the sum of the most consecutive primes?
"""

import math


def sieve(n):
    A = [True] * n
    for i in range(2, int(math.sqrt(n))):
        if A[i]:
            for j in range(i * i, n, i):
                A[j] = False
    return A


flag = sieve(1000000)
primes = [i for i in range(2, 1000000) if flag[i]]

result = 0
max_len = 0

for i in range(len(primes)):
    s = 0
    cnt = 0
    for j in range(i, len(primes)):
        s += primes[j]
        cnt += 1
        if s >= 1000000:
            break
        if flag[s] and cnt > max_len:
            max_len = cnt
            result = s
print(result)
