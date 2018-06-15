"""
Lattice paths


Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

![https://projecteuler.net/project/images/p015.gif]

How many such routes are there through a 20×20 grid?

"""

# C(40, 20)
from functools import reduce


def prod(xs):
    return reduce(lambda x, y: x * y, xs)


print(prod(range(21, 41)) // prod(range(1, 20+1)))
