data = open('input').read().splitlines()


def sign(x: int) -> int: return 1 if x > 0 else (-1 if x < 0 else 0)


def move_tail(hr, hc, tr, tc):
    # move tail
    if abs(hr - tr) > 1:
        tr += sign(hr - tr)
        tc += sign(hc - tc)
    elif abs(hc - tc) > 1:
        tc += sign(hc - tc)
        tr += sign(hr - tr)
    return tr, tc


def move_rope(l):
    seen = set([])
    seen.add((0, 0))
    rope = [[0, 0] for _ in range(l)]
    for line in data:
        line = line.strip().split()
        dir, n = line[0], int(line[1])
        for _ in range(n):
            # move head
            delta = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
            rope[0][0] += delta[dir][0]
            rope[0][1] += delta[dir][1]
            # move tail
            for s in range(1, l):
                tr, tc = move_tail(
                    rope[s-1][0], rope[s-1][1], rope[s][0], rope[s][1])
                rope[s] = [tr, tc]
                seen.add((rope[l-1][0], rope[l-1][1]))
    return len(seen)


# part 1
print(move_rope(2))
# part 2
print(move_rope(10))
