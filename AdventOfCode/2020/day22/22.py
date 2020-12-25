from copy import deepcopy
parts = open('input').read().split('\n\n')
p1, p2 = parts[0], parts[1]


def handle_input(p: str):
    ps = p.splitlines()[1:]
    res = [int(p) for p in ps]
    return res


p1 = handle_input(p1)
p2 = handle_input(p2)


def calc_score(l: list):
    return sum([x*y for x, y in zip(l, range(1, len(l)+1)[::-1])])


def play1(p1: list, p2: list):
    while len(p1) > 0 and len(p2) > 0:
        c1, c2 = p1[0], p2[0]
        p1, p2 = p1[1:], p2[1:]
        if c1 > c2:
            p1.append(c1)
            p1.append(c2)
        elif c1 < c2:
            p2.append(c2)
            p2.append(c1)
    score = calc_score(p1) if len(p1) != 0 else calc_score(p2)
    print(score)


play1(p1, p2)


def play2(p1, p2) -> int:
    history = set()
    while len(p1) > 0 and len(p2) > 0:
        if (tuple(p1), tuple(p2)) in history:
            return 1, calc_score(p1)
        history.add((tuple(p1), tuple(p2)))

        c1, c2 = p1[0], p2[0]
        p1, p2 = p1[1:], p2[1:]

        if len(p1) >= c1 and len(p2) >= c2:
            newp1 = deepcopy(p1[0:c1])
            newp2 = deepcopy(p2[0:c2])
            winner, _ = play2(newp1, newp2)
        else:
            winner = 1 if c1 > c2 else 2

        if winner == 1:
            p1.append(c1)
            p1.append(c2)
        elif winner == 2:
            p2.append(c2)
            p2.append(c1)

    score = calc_score(p1) if len(p1) != 0 else calc_score(p2)
    return (1, score) if len(p1) != 0 else (2, score)


_, ans2 = play2(p1, p2)
print(ans2)
