"""
Champernowne's constant
"""

i = 1
s = ''
while True:
    if len(s) > 1000000:
        break
    s += str(i)
    i += 1

idxs = [10**i for i in range(0, 7)]
result = 1
for idx in idxs:
    result *= int(s[idx-1])

print(result)
