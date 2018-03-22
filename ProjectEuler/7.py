"""
10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
"""
import math


def is_prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


i = 1
n = 2
while True:
    while not is_prime(n):
        n += 1
    if i == 10001:
        break
    n += 1  # prime + 1 cannot be prime except 2
    i += 1

print(n)
