"""
Non-abundant sums

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
"""

from math import sqrt


def factors(n):
    f = {1}
    sq = int(sqrt(n))
    for i in range(2, sq + 1):
        if n % i == 0:
            f.add(i)
            f.add(n // i)
    return sum(f)


abundants = set()
for i in range(2, 28124):
    if factors(i) > i:
        abundants.add(i)

result = 0
for i in range(1, 28124):
    yes = False
    for j in range(12, i):
        if j in abundants and i-j in abundants:
            yes = True
            break
    if not yes:
        result += i
print(result)
