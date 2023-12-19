from collections import defaultdict, deque
input = open("input").read().strip()
# input = open("input1").read().strip()
# input = open("input2").read().strip()

lines = input.splitlines()

maps = dict()
modules = dict()
for line in lines:
    src, dst = line.strip().split(' -> ')
    if src.startswith('%') or src.startswith('&'):
        modules[src[1:]] = src[0]
        src = src[1:]
    dst = dst.split(', ')
    maps[src] = dst

is_ff = lambda x: modules.get(x, ' ') == '%'
is_con = lambda x: modules.get(x, ' ') == '&'
is_rv = lambda x: x == 'rx'
LOW, HIGH = 0, 1
OFF, ON = 0, 1

state_ff = defaultdict(int)
state_con = defaultdict(dict)
repeated = dict()

def init():
    global state_ff, state_con, repeated
    state_ff = defaultdict(int)
    state_con = defaultdict(dict)
    repeated = dict()

    for line in lines:
        src, dst = line.strip().split(' -> ')
        if src.startswith('%') or src.startswith('&'):
            src = src[1:]
        dst = dst.split(', ')
        for d in dst:
            state_con[d][src] = LOW
        maps[src] = dst


def con_all_high(con):
    d = state_con[con]
    return all([x == HIGH for x in d.values()])


def push_button(i):
    hcnt, lcnt = 0, 0
    q = deque()
    q.append(('broadcaster', LOW))
    while q:
        mod, pulse = q.popleft()
        if pulse == LOW:
            lcnt += len(maps[mod])
        else:
            hcnt += len(maps[mod])

        for next in maps[mod]:
            if is_ff(next) and pulse == LOW:
                if state_ff[next] == OFF:
                    state_ff[next] = ON
                    q.append((next, HIGH))
                else:
                    state_ff[next] = OFF
                    q.append((next, LOW))
            elif is_con(next):
                # update
                state_con[next][mod] = pulse
                if con_all_high(next):
                    q.append((next, LOW))
                else:
                    if next not in repeated:
                        repeated[next] = i
                        if len(set(['ph', 'vn', 'kt', 'hn']) & set(repeated.keys())) == 4:
                            ans = repeated['ph'] * repeated['vn'] * repeated['kt'] * repeated['hn']
                            print(ans)
                            import sys
                            sys.exit(0)
                    q.append((next, HIGH))

    return lcnt + 1, hcnt

# 1
init()
N = 1000
ans1, ans2 = 0, 0
for i in range(1, N + 1):
    c1, c2 = push_button(i)
    ans1 += c1
    ans2 += c2
print(ans1 * ans2)

# 2
init()
N = 2
N = 10000000
ans1, ans2 = 0, 0
for i in range(1, N + 1):
    push_button(i)
