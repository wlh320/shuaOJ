lines = open("input").readlines()


def solve(xs, part2=False):
    pos = 50
    MOD = 100
    ans = 0

    def move(x):
        nonlocal ans, pos
        if part2:
            ans += abs(x) // MOD
            x = x % MOD if x > 0 else -((-x) % MOD)
        next = pos + x
        if pos != 0 and (next > MOD or next < 0) and part2:
            ans += 1
        pos = next % MOD
        if pos == 0:
            ans += 1

    for x in xs:
        move(x)
    return ans


xs = []
for line in lines:
    line = line.strip()
    d, x = line[0], int(line[1:])
    if d == "L":
        x = -x
    xs.append(x)


ans = solve(xs)
print(ans)
ans = solve(xs, part2=True)
print(ans)
