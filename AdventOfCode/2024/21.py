from functools import cache

lines = open("input").read().splitlines()


def solve(seq, n):

    cor1 = {ch: (i // 3, i % 3) for i, ch in enumerate("789456123 0A")}
    cor2 = {ch: (i // 3, i % 3) for i, ch in enumerate(" ^A<v>")}

    def to_seq(s, t, board, exp1, exp2):
        d1, d2 = board[t][0] - board[s][0], board[t][1] - board[s][1]
        d1 = "v" * d1 if d1 > 0 else "^" * (-d1)
        d2 = ">" * d2 if d2 > 0 else "<" * (-d2)

        if s in exp1 and t in exp2:
            yield d1 + d2 + "A"
            return
        if s in exp2 and t in exp1:
            yield d2 + d1 + "A"
            return

        if d1 and d2:
            yield d1 + d2 + "A"
            yield d2 + d1 + "A"
        else:
            yield d1 + "A" if d1 != "" else d2 + "A"

    seq12 = lambda s, t: to_seq(s, t, cor1, "0A", "147")
    seq22 = lambda s, t: to_seq(s, t, cor2, "^A", "<")

    @cache
    def dfs(i, seq):
        if i == n:
            return len(seq)

        seq = "A" + seq
        ans = 0
        for a, b in zip(seq, seq[1:]):
            seqs = seq22(a, b) if i != 0 else seq12(a, b)
            ans += min(dfs(i + 1, s) for s in seqs)
        return ans

    ans = dfs(0, seq)
    return ans


# 1
ans = 0
n = 2
for line in lines:
    r = solve(line, n + 1)
    ans += r * int(line[:-1])
print(ans)

# 2
ans = 0
n = 25
for line in lines:
    r = solve(line, n + 1)
    ans += r * int(line[:-1])
print(ans)
