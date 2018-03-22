"""
Digit factorials

Find the sum of all numbers which are equal to the sum of the factorial of their digits.
"""
from math import factorial as f


def df(n):
    return sum([f(int(i)) for i in str(n)])


# I don't know upper bound! sad !
# maybe because 9! * 7 < 9999999 ? Can prove it?
result = 0
for i in range(3, 9999999):
    if df(i) == i:
        result += i
print(result)
