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
        n.append((r + 3 + 1, c + 2))
    R[i] = n

GAS = open('input').read().splitlines()[0]


def move_rock(rock, dim, v):
    new_rock = []
    for block in rock:
        if dim == 0:
            new_rock.append((block[0] + v, block[1]))
        else:
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


def hash_room(room, lo, hi):
    lines = []
    for r in range(lo, hi + 1):
        dots = ['#' if (r, c) in room else '.' for c in range(C)]
        lines.append(''.join(dots))
    return '/'.join(lines)


def simulate(i, gi, max_n, find=False, find_depth=20):
    loop = {}
    room = set()
    height = 0
    hmap = {}
    for i in range(i, max_n):
        rock = R[i % N]
        rock = move_rock(rock, dim=0, v=height)
        while True:
            # try move left right
            g = GAS[gi % len(GAS)]
            v = 1 if g == '>' else -1
            try_rock = move_rock(rock, dim=1, v=v)
            gi += 1
            if not cannot_move(room, try_rock):
                rock = try_rock
            # try move down
            try_rock = move_rock(rock, dim=0, v=-1)
            if cannot_move(room, try_rock):
                max_height = fix_rock(room, rock)
                height = max(height, max_height)
                break
            else:
                rock = try_rock
        # find loop in simulation
        hmap[i] = height
        if find:
            hash = hash_room(room, lo=height-find_depth, hi=height)
            if (i % N, gi % len(GAS), hash) not in loop:
                loop[(i % N, gi % len(GAS), hash)] = (i, height)
            else:
                last, last_height = loop[(i % N, gi % len(GAS), hash)]
                delta = height - last_height
                # print(f'{i} is the same as {last}, height increase {delta}')
                loop_len = i - last
                return last, loop_len, delta
    return hmap


def calc_height(n):
    start, loop_len, delta = simulate(0, 0, max_n=n, find=True)
    hmap = simulate(0, 0, max_n=start+loop_len-1, find=False)
    init_num = (n - start) % loop_len
    loop_num = (n - start) // loop_len
    init_height = hmap[start+init_num]
    return init_height + delta * (loop_num)


# part1
ans = calc_height(2022 - 1)
print(ans)
# part2
ans = calc_height(1000000000000 - 1)
print(ans)
