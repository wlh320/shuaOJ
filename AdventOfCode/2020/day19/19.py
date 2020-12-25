lines = open('input').readlines()
scan = False
ins = []
RULES = {}

# parse
def trans_rule(rule):
    res = []
    for token in rule:
        if str.isdigit(token):
            res.append(int(token))
        else:
            res.append(token.strip('"'))
    return res

for line in lines:
    line = line.strip()
    if line == "":
        scan = True
        continue
    if not scan:
        num, rule = line.split(':')
        num, rules = int(num), rule.strip().split(' | ')
        RULES[num] = [trans_rule(rule.split(' ')) for rule in rules]
    else:
        ins.append(line)

# run
def func(rid, s):
    rules = RULES[rid]
    for rule in rules:
        if s == '':
            continue
        # rule like ['a']
        if rule[0] == 'a' or rule[0] == 'b':
            if s[0] == rule[0]: # eat one char
                yield s[1:]
            continue
        # rule like [1, 2]
        remainders = {s}
        for token in rule:
            remainders = {x for remainder in remainders
                                for x in func(token, remainder)}
        yield from remainders

ans1 = 0
for s in ins:
    x = 1 if '' in [x for x in func(0, s)] else 0
    ans1 += x
print(ans1)

RULES[8] = [[42], [42, 8]]
RULES[11] = [[42, 31], [42, 11, 31]]

ans2 = 0
for s in ins:
    x = 1 if '' in [x for x in func(0, s)] else 0
    ans2 += x
print(ans2)
