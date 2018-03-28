import math


def is_prime(n) -> bool:
    """检查是否是素数 return a bool"""
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def sieve(n) -> list:
    """埃拉托斯特尼筛法 return a bool list"""
    A = [True] * n
    for i in range(2, int(math.sqrt(n))):
        if A[i]:
            for j in range(i * i, n, i):
                A[j] = False
    return A


def sieve_of_phi(n) -> list:
    """筛法求欧拉函数 return a int list"""
    phi = [0] * (n+2)
    for i in range(1, n + 1):
        phi[i] = i
    for p in range(2, n+1):
        if phi[p] == p:  # prime
            phi[p] = p - 1
            for i in range(2*p, n+1, p):
                phi[i] = (phi[i] // p) * (p-1)
    return phi
