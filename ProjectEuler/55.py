"""
Lychrel numbers

How many Lychrel numbers are there below ten-thousand?

hint: below 10,000, less than 50 iterations
"""


def is_palin(n):
    return str(n) == str(n)[::-1]


result = 0
for i in range(1, 10000):
    it = 0
    n = i
    while it < 50:
        n = n + int(str(n)[::-1])
        it += 1
        if is_palin(n):
            break
    if it >= 50:
        result += 1
print(result)
