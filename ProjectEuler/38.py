"""
Pandigital multiples

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
"""
result = 0
for i in range(1, 10000):
    n = 1
    s = ''
    while len(s) < 9:
        s += str(i * n)
        n = n + 1
    if len(s) == 9 and '0' not in s and len(set(s)) == 9:
        if int(s) > result:
            result = int(s)

print(result)
