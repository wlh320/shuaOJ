from copy import deepcopy

# hardcoded input


class Monkey:
    def __init__(self, items, oper, mod, b1, b2):
        self.items = items
        self.oper = oper
        self.mod = mod
        self.b1 = b1
        self.b2 = b2
        self.count = 0

    def play(self, relif):
        ans = []
        for item in self.items:
            self.count += 1
            new = self.oper(item)
            new = relif(new)
            if new % self.mod == 0:
                ans.append((new, self.b1))
            else:
                ans.append((new, self.b2))
        self.items = []
        return ans

    def add_item(self, item):
        self.items.append(item)

    def is_empty(self):
        return self.items == []


# my input
monkeys = []
monkeys.append(Monkey([84, 66, 62, 69, 88, 91, 91], lambda x: x * 11, 2, 4, 7))
monkeys.append(Monkey([98, 50, 76, 99], lambda x: x * x, 7, 3, 6))
monkeys.append(Monkey([72, 56, 94], lambda x: x + 1, 13, 4, 0))
monkeys.append(Monkey([55, 88, 90, 77, 60, 67], lambda x: x + 2, 3, 6, 5))
monkeys.append(Monkey([69, 72, 63, 60, 72, 52, 63, 78],
               lambda x: x * 13, 19, 1, 7))
monkeys.append(Monkey([89, 73], lambda x: x + 5, 17, 2, 0))
monkeys.append(Monkey([78, 68, 98, 88, 66], lambda x: x + 6, 11, 2, 5))
monkeys.append(Monkey([70], lambda x: x + 7, 5, 1, 3))
M = deepcopy(monkeys)


N = 20
l = len(monkeys)

for _ in range(N):
    for i in range(l):
        res = monkeys[i].play(relif=lambda x: x // 3)
        for item, to in res:
            monkeys[to].add_item(item)
    # for i in range(l):
        # print(f'Monkey {i}: items: {monkeys[i].items}')

monkeys.sort(key=lambda m: -m.count)
print(monkeys[0].count * monkeys[1].count)

# part 2

# my input
monkeys = deepcopy(M)
MM = 1
for m in monkeys:
    MM *= m.mod

N = 10000
for _ in range(N):
    for i in range(l):
        res = monkeys[i].play(relif=lambda x: x % MM)
        for item, to in res:
            monkeys[to].add_item(item)

monkeys.sort(key=lambda m: -m.count)
print(monkeys[0].count * monkeys[1].count)
