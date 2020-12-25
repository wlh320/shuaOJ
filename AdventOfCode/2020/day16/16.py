lines = open('input').readlines()
section = 0
my_ticket = []
tickets = []
valid_range = []
for line in lines:
    line = line.strip()
    if line == '': continue
    if line == 'your ticket:':
        section = 1
        continue
    if line == 'nearby tickets:':
        section = 2
        continue
    if section == 0: # range
        line = line.split(': ')
        name, line = line[0], line[1]
        line = line.split(' or ')
        r1, r2 = line[0].split('-'), line[1].split('-')
        r1 = (int(r1[0]), int(r1[1]), name)
        r2 = (int(r2[0]), int(r2[1]), name)
        valid_range.append(r1)
        valid_range.append(r2)
    elif section == 1: # my
        line = list(map(int, line.split(',')))
        my_ticket = line
    elif section == 2: # nearby
        line = list(map(int, line.split(',')))
        tickets.append(line)

# 1
valid_tickets = []
def check_one_field(valid_range, field):
    check = [r0 <= field <= r1 for r0, r1, _ in valid_range]
    return not any(check)
ans = 0
for ticket in tickets:
    valid = True
    for field in ticket:
        if check_one_field(valid_range, field):
            ans += field
            valid = False
    if valid:
        valid_tickets.append(ticket)
print(ans)

# 2
def check_one_ticket(valid_range, ticket):
    candi_names = []
    for field in ticket:
        candi_field = set()
        for r0, r1, name in valid_range:
            if r0 <= field <= r1:
                candi_field.add(name)
        candi_names.append(candi_field)
    return candi_names

guess = check_one_ticket(valid_range, my_ticket)
for ticket in valid_tickets:
    candi = check_one_ticket(valid_range, ticket)
    guess = [x & y for x, y in zip(guess, candi)]

columns = {}
while True:
    for i, s in enumerate(guess):
        if len(s) == 1:
            name = s.pop()
            columns[name] = i
            break
    new_guess = []
    for names in guess:
        if name in names:
            names.remove(name)
        new_guess.append(names)
    guess = new_guess
    if len(columns) == len(guess):
        break

ans = 1
for name, column in columns.items():
    if 'departure' in name:
        ans *= my_ticket[column]
print(ans)
