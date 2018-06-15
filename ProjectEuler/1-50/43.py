"""
Sub-string divisibility
Find the sum of all 0 to 9 pandigital numbers with this property.
"""

from itertools import permutations

candidates = permutations('0123456789', 10)

result = 0
divisors = [None, 2, 3, 5, 7, 11, 13, 17]
for n in candidates:
    n = ''.join(n)
    yes = True
    for i in range(1, 8):
        if int(n[i:i+3]) % divisors[i] != 0:
            yes = False
            break
    if yes:
        result += int(n)

print(result)
