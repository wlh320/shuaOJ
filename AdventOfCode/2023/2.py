lines = open('input').readlines()


# only 12 red cubes, 13 green cubes, and 14 blue cubes

# 1
ans = 0
for line in lines:
    line = line.strip()
    id, games = line.split(': ')
    id = int(id.split(' ')[1])
    games = games.split('; ')

    ok = True
    for game in games:
        game = game.split(', ')
        for ball in game:
            n, color = ball.split()
            n = int(n)
            if color == 'red' and n > 12:
                ok = False
            if color == 'green' and n > 13:
                ok = False
            if color == 'blue' and n > 14:
                ok = False
    if ok:
        ans += id
print(ans)

# 2
ans = 0
for line in lines:
    line = line.strip()
    id, games = line.split(': ')
    id = int(id.split(' ')[1])
    games = games.split('; ')
    d = dict()
    for game in games:
        game = game.split(', ')
        for ball in game:
            n, color = ball.split()
            n = int(n)
            if color in d:
                d[color] = max(d[color], n)
            else:
                d[color] = n
    r = d.get('red', 0)
    g = d.get('green', 0)
    b = d.get('blue', 0)
    ans += r * g * b
print(ans)


