"""
Convergents of e

Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

连分数
"""
a = [2]
for k in range(1, 34):
    a.extend([1, 2*k, 1])
a.append(1)

h = [a[0], a[0]*a[1]+1] + [0] * 98
k = [1, a[1]] + [0] * 98
for i in range(2, 100):
    h[i] = a[i] * h[i-1] + h[i-2]
    k[i] = a[i] * k[i-1] + k[i-2]
print(sum(map(int, str(h[99]))))
