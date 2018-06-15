"""
Square digit chains
How many starting numbers below ten million will arrive at 89?
"""


def sq_sum(n):
    return sum([int(i)**2 for i in str(n)])


result = 10000000 - 1
note = {}
for i in range(1, 10000000):
    s = i
    while True:
        if s == 1 or s == 89:
            note[i] = s
            break
        s = sq_sum(s)
        if s in note:
            s = note[s]
    if s == 1:  # end-at-1 is less than end-at-89
        result -= 1
print(result)
