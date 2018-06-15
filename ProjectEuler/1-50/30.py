"""
Digit fifth powers

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
"""
# One Question: how to determine the upper bound?
result = 0
for i in range(2, 1000000):
    digits = list(map(int, str(i)))
    if i == sum([i**5 for i in digits]):
        result += i
print(result)
