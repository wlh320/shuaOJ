from collections import Counter

s = open("input").read().strip()
# s = open('input1').read().strip()
lines = s.splitlines()


def process_cards(cards, part):
    cards = list(cards)
    ans = []
    d = {"A": 14, "K": 13, "Q": 12, "J": 11 if part == 1 else 1, "T": 10}
    for c in cards:
        if c in d.keys():
            ans.append(d[c])
        else:
            assert c.isdigit()
            ans.append(int(c))
    return ans


def solve_part1():
    def make_sortable(cards):
        c = Counter(cards)
        c = list(v for (_, v) in c.items())
        c.sort(reverse=True)
        c = (c, cards)
        return c

    part = 1
    users = []
    for line in lines:
        cards, val = line.strip().split()
        cards, val = process_cards(cards, part), int(val)
        cards = make_sortable(cards)
        users.append((cards, val))

    ans = 0
    users.sort(key=lambda x: x[0], reverse=True)
    n = len(users)
    for i, u in enumerate(users):
        ans += (n - i) * u[1]
    print(ans)


def solve_part2():
    from functools import cmp_to_key

    def get_score(cards):
        c = Counter(cards)
        c = list(v for (_, v) in c.items())
        c.sort(reverse=True)
        return c

    def j_max_score(cards):
        f = [x for x in cards if x != 1]
        num_j = len([x for x in cards if x == 1])
        score = get_score(f)
        if len(score) == 0:
            return [5]
        else:
            score[0] += num_j
        return score

    def cmp(c1, c2):
        c1, c2 = c1[0], c2[0]
        s1 = j_max_score(c1)
        s2 = j_max_score(c2)
        if s1 < s2:
            return -1
        elif s1 == s2:
            if c1 < c2:
                return -1
            elif c1 == c2:
                return 0
            elif c1 > c2:
                return 1
        return 1

    part = 2
    users = []
    for line in lines:
        cards, val = line.strip().split()
        cards, val = process_cards(cards, part), int(val)
        users.append((cards, val))

    ans = 0
    users.sort(key=cmp_to_key(cmp), reverse=True)
    n = len(users)
    for i, u in enumerate(users):
        ans += (n - i) * u[1]
    print(ans)


solve_part1()
solve_part2()
