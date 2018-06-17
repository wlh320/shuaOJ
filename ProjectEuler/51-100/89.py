"""
Roman numerals
Find the number of characters saved by writing each of these in their minimal form.
"""
from urllib import request
numbers = request.urlopen("https://projecteuler.net/project/resources/p089_roman.txt").read().decode('utf-8').splitlines()


def roman2int(roman):
    d = dict()
    keys = "IVXLCDM"
    vals = [1, 5, 10, 50, 100, 500, 1000]
    for i, key in enumerate(keys):
        d[key] = vals[i]
    result = 0
    for i, ch in enumerate(roman):
        if i != len(roman) - 1 and d[ch] < d[roman[i + 1]]:
            result -= d[ch]
        else:
            result += d[ch]
    return result


def int2roman(n):
    digits = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I", ""]
    values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 0]
    roman = ""
    while n != 0:
        i = 0
        while n < values[i]:
            i += 1
        n -= values[i]
        roman += digits[i]
    return roman


count = 0
for number in numbers:
    i = roman2int(number)
    new_number = int2roman(i)
    count += (len(number) - len(new_number))

print(count)
