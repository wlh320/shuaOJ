"""
Powerful digit sum
Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
"""
result = 0
for a in range(1, 100):
    for b in range(1, 100):
        dsum = sum(map(int, str(a**b)))
        result = max(result, dsum)
print(result)
