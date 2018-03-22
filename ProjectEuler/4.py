"""
Largest palindrome product
"""
result = 0
for i in range(100, 1000):
    for j in range(100, 1000):
        p = i * j
        if str(p) == str(p)[::-1]:
            result = max(p, result)
print(result)
