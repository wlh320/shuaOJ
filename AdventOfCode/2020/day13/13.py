from math import ceil, gcd
from gmpy2 import invert
from functools import reduce
lines = open('input').readlines()
target = int(lines[0].strip())
buses = list(map(lambda x: x.strip(), lines[1].split(',')))
m, a = [], []
ans1 = []
for i, bus in enumerate(buses):
    if bus == 'x':
        continue
    bus = int(bus)
    x = ceil(target / bus) * bus
    ans1.append((bus, x-target))
    m.append(bus)
    a.append((bus - i) % bus)
x, y = min(ans1, key=lambda x: x[1])
print(x*y)
# 2

# 网上找的 CRT 实现
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
    return (g, x - (b // a) * y, y)

def crt(m, a):
    assert(len(m) == len(a))
    m1, a1, lcm = m[0], a[0], m[0]
    num = len(a)
    for i in range(1, num):
        m2 = m[i]
        a2 = a[i]
        c = a2-a1
        g, k1, k2 = egcd(m1, m2)
        lcm = lcm*m[i]//gcd(lcm, m[i])
        if c % g:
            print('No Answer!')
            return 0
        x0 = c//g*k1
        t = m2//g
        x0 = (x0 % t+t) % t
        a1 += m1*x0
        m1 = m2//g*m1
    return a1


print(crt(m, a))
