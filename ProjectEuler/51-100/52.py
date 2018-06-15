"""
Permuted multiples

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
"""


def check(a, *others):
    s = set(str(a))
    for num in others:
        if set(str(num)) != s:
            return False
    return True


a = 1
while True:
    b, c, d, e, f = a * 2, a * 3, a * 4, a * 5, a * 6
    if check(a, b, c, d, e, f):
        print(a)
        break
    a += 1
