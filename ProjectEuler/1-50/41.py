"""
Pandigital prime

What is the largest n-digit pandigital prime that exists?
"""
import math
from itertools import permutations
NUM = '123456789'


def is_prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


result = 0
for n in range(9, 0, -1):
    perms = permutations(NUM[0:n], n)
    add_new = False
    for num in perms:
        num = int(''.join(num))
        if is_prime(num):
            result = max(result, num)
            add_new = True
    if add_new:
        break

print(result)
