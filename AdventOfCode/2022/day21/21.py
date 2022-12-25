import z3
data = open('input').read().splitlines()
monkeys = {}
for line in data:
    name, expr = line.split(': ')
    try:
        expr = [int(expr)]
    except Exception:
        expr = expr.split()
    monkeys[name] = expr


def parse(name):
    if len(monkeys[name]) == 1:
        return monkeys[name][0]
    else:
        m1, op, m2 = monkeys[name]
        m1 = parse(m1)
        m2 = parse(m2)
        match op:
            case '+': return m1 + m2
            case '-': return m1 - m2
            case '*': return m1 * m2
            case '/': return m1 // m2


# part1
ans = parse('root')
print(ans)


def parse2(name):
    if name == "humn":
        return z3.Int('x')
    if len(monkeys[name]) == 1:
        return monkeys[name][0]
    else:
        m1, op, m2 = monkeys[name]
        m1 = parse2(m1)
        m2 = parse2(m2)
        if name == "root":
            return m1 == m2
        else:
            match op:
                case '+': return m1 + m2
                case '-': return m1 - m2
                case '*': return m1 * m2
                case '/': return m1 / m2


# part2
expr = parse2("root")
z3.solve(expr)
