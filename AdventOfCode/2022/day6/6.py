line = open('input').readline()
line = line.strip()
cnt = 0
# part 1
for a, b, c, d in zip(line, line[1:], line[2:], line[3:]):
    cnt += 1
    if len(set([a, b, c, d])) == 4:
        print(cnt + 3)
        break

# part 2
cnt = 0
for i in range(0, len(line)):
    cnt += 1
    if len(set(line[i:i+14])) == 14:
        print(cnt + 13)
        break
