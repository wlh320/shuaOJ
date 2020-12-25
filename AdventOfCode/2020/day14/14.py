import re
from itertools import chain, combinations
lines = open('input').readlines()
mem = {}

def get_masks(mask):
    mask0, mask1 = 0, 0
    for x in mask:
        mask0 <<= 1
        mask1 <<= 1
        if x == '0':
            mask0 |= 1
        elif x == '1':
            mask1 |= 1
    return ~mask0, mask1

for line in lines:
    line = line.strip().split(' = ')
    if line[0] == 'mask':
        mask = line[1]
        mask0, mask1 = get_masks(mask)
    if 'mem' in line[0]:
        addr = int(re.match(r'mem\[(\d+)\]', line[0]).groups()[0])
        num = int(line[1])
        num |= mask1
        num &= mask0
        mem[addr] = num
print(sum(mem.values()))

# 2
def get_masks2(mask):
    mask1, maskx = 0, 0
    xs = []
    base = 1 << (len(mask))
    for x in mask:
        maskx <<= 1
        mask1 <<= 1
        base >>= 1
        if x == '1':
            mask1 |= 1
        elif x == 'X':
            maskx |= 1
            xs.append(base)
    powerset = chain.from_iterable(combinations(xs, r) for r in range(len(xs)+1))
    return mask1, ~maskx, list(powerset)

mem = {}
for line in lines:
    line = line.strip().split(' = ')
    if line[0] == 'mask':
        mask = line[1]
        mask1, maskx, powerset = get_masks2(mask)
    if 'mem' in line[0]:
        addr = int(re.match(r'mem\[(\d+)\]', line[0]).groups()[0])
        num = int(line[1])
        addr |= mask1
        addr &= maskx
        for s in powerset:
            mem[addr | sum(s)] = num
print(sum(mem.values()))
