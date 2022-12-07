line = open('input').readline()
line = line.strip()


def find_marker(buf: str, l: int) -> int:
    for i in range(len(buf)):
        if len(set(buf[i:i+l])) == l:
            return i + l
    return -1


# part 1
ans = find_marker(line, 4)
print(ans)

# part 2
ans = find_marker(line, 14)
print(ans)
