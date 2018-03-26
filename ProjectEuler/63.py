"""
Powerful digit counts
How many n-digit positive integers exist which are also an nth power?

a ^ n > 10 ^ (n-1) => a < 10
9 ^ n < 10 ^ (n-1) => n < 22
"""
result = 0
for n in range(1, 23):
    mini = 10 ** (n-1)
    maxi = 10 ** n - 1
    for a in range(1, 11):
        p = pow(a, n)
        if p >= mini and p <= maxi:
            result += 1
    n += 1
print(result)
