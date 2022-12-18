# import re
# PTN = re.compile(r'^(.+)$')
ROOM = set()
height = 0
C = 7
R = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],
    [(0, 1), (1, 0), (1, 1), (1, 2), (2, 1)],
    [(0, 0), (0, 1), (0, 2), (1, 2), (2, 2)],
    [(0, 0), (1, 0), (2, 0), (3, 0)],
    [(0, 0), (0, 1), (1, 0), (1, 1)],
]
for i in range(5):
    n = []
    for r, c in R[i]:
        n.append((r + 4, c + 2))
    R[i] = n

# print(R)
gas = open('input').read().splitlines()[0]
# print(data)


def add_height(rock, height):
    new_rock = []
    for block in rock:
        new_rock.append((block[0] + height, block[1]))
    return new_rock


def move_lr(rock, v):
    new_rock = []
    for block in rock:
        new_rock.append((block[0], block[1] + v))
    return new_rock


def cannot_move(rock):
    for r, c in rock:
        if r < 1 or c < 0 or c > C - 1:
            return True
        if (r, c) in ROOM:
            return True
    return False


def fix_rock(rock):
    max_height = 0
    for block in rock:
        ROOM.add(block)
        max_height = max(max_height, block[0])
    return max_height


def print_room():
    img = []
    for r in range(10):
        s = []
        for c in range(C):
            if (r, c) in ROOM:
                s.append('#')
            else:
                s.append('.')
        img.append(''.join(s))
    for line in img[::-1]:
        print(line)
    print()


gi = 0
for i in range(2022):
    rock = R[i % 5]
    rock = add_height(rock, height)
    while True:
        # print(height, rock)
        # try move left right
        g = gas[gi % len(gas)]
        assert g in '<>'
        if g == '>':
            try_rock = move_lr(rock, 1)
        elif g == '<':
            try_rock = move_lr(rock, -1)
        gi += 1
        if not cannot_move(try_rock):
            rock = try_rock
        # try move down
        try_rock = add_height(rock, -1)
        if cannot_move(try_rock):
            max_height = fix_rock(rock)
            height = max(height, max_height)
            # print(rock)
            break
        else:
            rock = try_rock
    # print_room()
print(height)
