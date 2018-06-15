"""
Triangular, pentagonal, and hexagonal

Find the next triangle number that is also pentagonal and hexagonal.
"""
t = {n*(n+1)//2 for n in range(1, 100000)}
p = {n*(3*n-1)//2 for n in range(1, 100000)}
h = {n*(2*n-1) for n in range(1, 100000)}
s = t & p & h
for num in s:
    if num > 40755:
        print(num)
        break
