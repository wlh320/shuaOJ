"""
Totient maximum

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
"""


def sieve_of_phi(n):
    """筛法求欧拉函数"""
    phi = [0] * (n+2)
    for i in range(1, n + 1):
        phi[i] = i
    for p in range(2, n+1):
        if phi[p] == p:  # prime
            phi[p] = p - 1
            for i in range(2*p, n+1, p):
                phi[i] = (phi[i] // p) * (p-1)
    return phi


max_f = 0
result = 0
phi = sieve_of_phi(1000000)
for n in range(2, 1000000):
    if n / phi[n] > max_f:
        result = n
        max_f = n / phi[n]
print(result)
