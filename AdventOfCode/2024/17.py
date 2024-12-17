lines = open("input").read().strip()

regs, prog = lines.split("\n\n")
regs = regs.splitlines()

ra = int(regs[0].split(": ")[1])
rb = int(regs[1].split(": ")[1])
rc = int(regs[2].split(": ")[1])
prog = list(map(int, prog.split(": ")[1].split(",")))


def run(ra, rb, rc, prog):

    def get(n) -> int:
        match n:
            case 0:
                return 0
            case 1:
                return 1
            case 2:
                return 2
            case 3:
                return 3
            case 4:
                return ra
            case 5:
                return rb
            case 6:
                return rc
        assert False

    pc = 0
    output = []
    while pc < len(prog):
        op = prog[pc]
        lit = prog[pc + 1]
        combo = get(lit)

        match op:
            case 0:
                ra = ra // (2**combo)
            case 1:
                rb = rb ^ lit
            case 2:
                rb = combo % 8
            case 3:
                if ra != 0:
                    pc = lit
                    continue
            case 4:
                rb = rb ^ rc
            case 5:
                output.append(combo % 8)
            case 6:
                rb = ra // (2**combo)
            case 7:
                rc = ra // (2**combo)
        pc += 2

    return output


# 1
s = run(ra, rb, rc, prog)
s = ",".join(list(map(str, s)))
print(s)

# 2

N = 2**10
tgt = prog
candidates = []


def dfs(i, mid7, full):
    if i == len(tgt):
        output = run(full, 0, 0, prog)
        if output == tgt:
            candidates.append(full)
        return

    for n in range(8):
        x = (n << 7) + mid7
        output = run(x, 0, 0, prog)
        if output[0] == tgt[i]:
            nf = full + (n << (7 + i * 3))
            dfs(i + 1, (x >> 3), nf)


for n in range(N):
    output = run(n, 0, 0, prog)
    if output[0] == tgt[0]:
        dfs(1, n >> 3, n)

print(sorted(candidates)[0])
