"""
Passcode derivation
Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
"""
from urllib import request
from functools import cmp_to_key
codes = request.urlopen("https://projecteuler.net/project/resources/p079_keylog.txt").read().decode()
codes = set(codes.splitlines())
after = {}
digits = list(set(''.join(codes)))
for digit in digits:
    after[digit] = set()
for (a, b, c) in codes:
    after[a].add(b)
    after[a].add(c)

key = cmp_to_key(lambda x, y: 1 if x in after[y] else -1)
print(''.join(sorted(digits, key=key)))
