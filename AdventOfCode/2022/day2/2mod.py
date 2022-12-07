data = open('input').readlines()
# part 1
ans = 0
for line in data:
    a, b = line.strip().split()
    a, b = ord(a) - ord('A'), ord(b) - ord('X')
    # diff: 0 draw 1 win 2 lose
    S = {0: 3, 1: 6, 2: 0}
    ans += b + 1
    ans += S[(b - a) % 3]
print(ans)

# part2
ans = 0
for line in data:
    a, b = line.strip().split()
    a, b = ord(a) - ord('A'), ord(b) - ord('X')
    # input: 0 lose 1 draw 2 win
    S = {0: 0, 1: 3, 2: 6}
    ans += S[b]
    M = {0: 2, 1: 0, 2: 1}  # map to right diff
    my = (a + M[b]) % 3
    ans += (my + 1)
print(ans)
