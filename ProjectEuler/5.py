"""
Smallest multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
"""


def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)


def lcm(a, b):
    return a * b // gcd(a, b)


m = 1
for i in range(2, 21):
    m = lcm(m, i)
print(m)
