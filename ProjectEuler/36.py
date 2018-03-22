"""
Double-base palindromes

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
"""

result = 0
for i in range(1000000):
    s10 = str(i)
    s2 = "{:b}".format(i)
    if s10 == s10[::-1] and s2 == s2[::-1]:
        result += i

print(result)
