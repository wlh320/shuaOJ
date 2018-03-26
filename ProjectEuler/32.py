"""
Pandigital products
Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
"""
sets = set()
for a in range(1, 10001):
    for b in range(a, 10001):
        c = a * b
        s = str(a) + str(b) + str(c)
        if len(s) > 9:
            break
        if '0' not in s and len(set(s)) == 9:
            sets.add(c)

print(sum(sets))
