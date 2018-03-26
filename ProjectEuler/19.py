"""
Counting Sundays

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
"""


# Zeller's formula
def weekday(y, m, d):
    if m == 1 or m == 2:
        m += 12
        y -= 1
    day = (d + (13*m+13)//5 + y + y//4 - y//100 + y//400) % 7
    return day


result = 0
for y in range(1901, 2001):
    for m in range(1, 13):
        if weekday(y, m, 1) == 1:
            result += 1
print(result)
