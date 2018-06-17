"""
Digit factorial chains
How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?
"""

DIGFAC = [1]
for i in range(1, 10):
    DIGFAC.append(DIGFAC[-1] * i)


def dig_fac_sum(n):
    return sum([DIGFAC[int(i)] for i in str(n)])


note = dict()
count = 0
for i in range(0, 1000000):
    chains = set([i])
    n = i
    while True:
        if n in note:
            n = note[n]
        else:
            x = dig_fac_sum(n)
            note[n] = x
            n = x
        if n in chains:
            break
        else:
            chains.add(n)
    if len(chains) == 60:
        count += 1
print(count)
