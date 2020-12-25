cpub = 9789649
dpub = 3647239

for x in range(1, 100000000):
    if pow(7, x, 20201227) == cpub:
        cloop = x
        break

for x in range(1, 100000000):
    if pow(7, x, 20201227) == dpub:
        dloop = x
        break

print(pow(dpub, cloop, 20201227))
# print(pow(cpub, dloop, 20201227))
