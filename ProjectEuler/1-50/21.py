"""
Amicable numbers

Evaluate the sum of all the amicable numbers under 10000.
"""
import math


def divisors_prod(n):
    d = [1]
    root = int(math.sqrt(n))
    for i in range(2, root):
        if n % i == 0:
            d.append(i)
            d.append(n // i)
    if n % root == 0:
        d.append(root)
    if len(d) == 2:  # prime
        return -1
    return sum(d)


s = 0
checked = {}
for i in range(2, 10000):
    if i in checked:
        continue
    cp = divisors_prod(i)
    if cp >= 10000 or cp < 0 or cp == i:
        continue
    checked[i] = True
    checked[cp] = True
    if divisors_prod(cp) == i:
        s += i
        s += cp

print(s)
