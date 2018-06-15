"""
Largest exponential

determine which line number has the greatest numerical value.
"""
from urllib import request
from math import log

file = request.urlopen("https://projecteuler.net/project/resources/p099_base_exp.txt")
file = file.read().decode().splitlines()
pairs = []
for pair in file:
    a, b = pair.split(",")
    pairs.append((int(a), int(b)))

max_a, max_b = 0, 0
max_idx = 0

for i, (a, b) in enumerate(pairs):
    if a <= max_a and b <= max_b:
        continue
    elif (a >= max_a and b >= max_b) or (b * log(a) > max_b * log(max_a)):
        max_a = a
        max_b = b
        max_idx = i

print(max_idx + 1)
