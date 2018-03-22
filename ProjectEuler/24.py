"""
Lexicographic permutations

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
"""

from itertools import permutations
print(''.join(list(permutations('0123456789', 10))[999999]))
