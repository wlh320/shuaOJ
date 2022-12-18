C = 7
R = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],
    [(0, 1), (1, 0), (1, 1), (1, 2), (2, 1)],
    [(0, 0), (0, 1), (0, 2), (1, 2), (2, 2)],
    [(0, 0), (1, 0), (2, 0), (3, 0)],
    [(0, 0), (0, 1), (1, 0), (1, 1)],
]
N = len(R)
for i in range(N):
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


def cannot_move(room, rock):
    for r, c in rock:
        if r < 1 or c < 0 or c > C - 1:
            return True
        if (r, c) in room:
            return True
    return False


def fix_rock(room, rock):
    max_height = 0
    for block in rock:
        room.add(block)
        max_height = max(max_height, block[0])
    return max_height


def print_room(room, lo, hi):
    img = []
    for r in range(lo, hi + 1):
        s = []
        for c in range(C):
            if (r, c) in room:
                s.append('#')
            else:
                s.append('.')
        img.append(''.join(s))
    # for line in img[::-1]:
        # print(line)
    # print()
    return '/'.join(img)


LOOP = dict()

MAX_N = 1000000000000


def simulate(i, gi, max_n, find=False, find_depth=20):
    room = set()
    height = 0
    hmap = {}
    for i in range(i, max_n):
        rock = R[i % N]
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
            if not cannot_move(room, try_rock):
                rock = try_rock
            # try move down
            try_rock = add_height(rock, -1)
            if cannot_move(room, try_rock):
                max_height = fix_rock(room, rock)
                height = max(height, max_height)
                # print(rock)
                break
            else:
                rock = try_rock
        hmap[i] = height
        # ROOM = clean_room()
        if find:
            img = print_room(room, lo=height-find_depth, hi=height)
            if (i % N, gi % len(gas), img) not in LOOP:
                LOOP[(i % N, gi % len(gas), img)] = (i, height)
            else:
                last, last_height = LOOP[(i % N, gi % len(gas), img)]
                delta = height - last_height
                # print(f'{i} is the same as {last}, height increase {delta}')
                loop_len = i - last
                return last, loop_len, delta
    return hmap


def calc_loop(n, start, loop_len, delta):
    hmap = simulate(0, 0, max_n=start+loop_len-1, find=False)
    init_num = (n - start) % loop_len
    loop_num = (n - start) // loop_len
    init_height = hmap[start+init_num]
    return init_height + delta * (loop_num)


MAX_N = 1_0000_0000_0000
start, loop_len, delta = simulate(0, 0, max_n=MAX_N, find=True)
ans = calc_loop(MAX_N - 1, start, loop_len, delta)
print(ans)
