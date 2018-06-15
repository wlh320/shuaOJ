"""
Combinatoric selections
How many, not necessarily distinct, values of  C(n, r), for 1 ≤ n ≤ 100, are greater than one-million?
"""
# generate a YangHui triangle
yh = [1] * 101
result = 0

for i in range(1, 101):
    old = yh.copy()
    for j in range(0, i+1):
        if j == 0 or j == i:
            yh[j] = 1
        else:
            yh[j] = old[j] + old[j-1]
        if yh[j] > 1000000:
            result += 1
print(result)
