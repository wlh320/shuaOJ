"""
Goldbach's other conjecture

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
"""
import math


def is_prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


i = 1
while True:
    i += 2
    if is_prime(i):
        continue
    s = 1
    yes = False
    while 2 * s * s < i:
        diff = i - 2 * s * s
        if is_prime(diff):
            yes = True
            break
        s += 1
    if not yes:
        print(i)
        break
