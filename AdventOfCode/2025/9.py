lines = open("input").read().splitlines()
tiles = [tuple(map(int, line.split(","))) for line in lines]


def area(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1)


# 1
ans = 0
for p1 in tiles:
    for p2 in tiles:
        ans = max(ans, area(p1, p2))
print(ans)


# 2
def is_invalid(p1, p2, edges):
    """having edge in rectangle"""
    x1, y1 = p1
    x2, y2 = p2
    min_x, max_x = min(x1, x2), max(x1, x2)
    min_y, max_y = min(y1, y2), max(y1, y2)
    for edge in edges:
        (ex1, ey1), (ex2, ey2) = edge
        min_ey, max_ey = min(ey1, ey2), max(ey1, ey2)
        min_ex, max_ex = min(ex1, ex2), max(ex1, ex2)
        # vertical edge
        if (
            ex1 == ex2
            and min_x < ex1 < max_x
            and max(min_ey, min_y) < min(max_ey, max_y)
        ):
            return True
        # horizontal edge
        if (
            ey1 == ey2
            and min_y < ey1 < max_y
            and max(min_ex, min_x) < min(max_ex, max_x)
        ):
            return True
    return False


ans = 0
edges = list(zip(tiles, tiles[1:])) + [(tiles[-1], tiles[0])]
for p1 in tiles:
    for p2 in tiles:
        x1, y1 = p1
        x2, y2 = p2
        s = area(p1, p2)
        if s < ans:
            continue
        if not is_invalid(p1, p2, edges):
            ans = max(ans, s)
print(ans)
