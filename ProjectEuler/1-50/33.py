"""
Digit cancelling fractions
If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
"""
from itertools import combinations


def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)


def check(a, b, na, nb):
    a, b, na, nb = map(int, (a, b, na, nb))
    gab = gcd(a, b)
    gnab = gcd(na, nb)
    if na // gnab == a // gab and nb // gnab == b // gab:
        return True
    return False


pa = 1
pb = 1
cp = combinations('123456789', 2)
for a, b in cp:
    v = int(a) / int(b)
    for c in '123456789':
        ax = [a+c, a+c, c+a, c+a]
        bx = [b+c, c+b, b+c, c+b]
        for na, nb in zip(ax, bx):
            if check(a, b, na, nb):
                pa *= int(a)
                pb *= int(b)
print(pb // gcd(pa, pb))
