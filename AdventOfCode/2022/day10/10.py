data = open('input').readlines()
xs = {0: 1}  # register value after each cycle
t = 1
for line in data:
    line = line.strip()
    if line == "noop":
        xs[t] = xs[t - 1]
        t += 1
    else:
        line = line.split()
        cmd, n = line[0], int(line[1])
        assert cmd == "addx"
        xs[t] = xs[t - 1]
        xs[t + 1] = xs[t] + n
        t += 2

ans = 0
for t in [20, 60, 100, 140, 180, 220]:
    ans += (t * xs[t - 1])
print(ans)

# part2
R, C = 6, 40
crt = ['.' for _ in range(R * C)]
for t in range(R*C):
    pos = xs[t]
    col = t % C
    if col == pos - 1 or col == pos or col == pos + 1:
        crt[t] = '#'

for x in range(0, R*C, C):
    print(''.join(crt[x:x+C]))
