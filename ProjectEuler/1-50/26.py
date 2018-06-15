"""
Reciprocal cycles

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
"""
result = 0
max_len = 0
for i in range(3, 1000):
    if i % 2 == 0 or i % 5 == 0:
        continue
    j = 1
    while True:
        xx = 10 ** j - 1
        if xx % i == 0:
            break
        j += 1
    if j > max_len:
        max_len = j
        result = i

print(result)
