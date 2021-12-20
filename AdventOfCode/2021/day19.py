# copy other's rotation code
def xy_rotations():
    yield lambda x, y, z: (x, y, z)
    yield lambda x, y, z: (y, -x, z)
    yield lambda x, y, z: (-x, -y, z)
    yield lambda x, y, z: (-y, x, z)


def yz_rotations():
    yield lambda x, y, z: (x, y, z)
    yield lambda x, y, z: (x, z, -y)
    yield lambda x, y, z: (x, -y, -z)
    yield lambda x, y, z: (x, -z, y)


def xz_rotations():
    yield lambda x, y, z: (x, y, z)
    yield lambda x, y, z: (z, y, -x)
    yield lambda x, y, z: (-x, y, -z)
    yield lambda x, y, z: (-z, y, x)


def rotations(xyzs):
    rotated_beacons = set()
    for xy in xy_rotations():
        for yz in yz_rotations():
            for xz in xz_rotations():
                rotated_beacons = set()
                for xyz in xyzs:
                    rotated_beacons.add(xz(*yz(*xy(*xyz))))
                yield rotated_beacons


real_xyz = {}
xyz = {}


def compare(sid1, sid2):
    s1, s2 = xyz[sid1], xyz[sid2]
    new_s2_gen = rotations(s2)
    for new_s2 in new_s2_gen:
        for x1, y1, z1 in s1:
            relative_diffs = []
            for x11, y11, z11 in s1:
                relative_diffs.append((x11 - x1, y11 - y1, z11 - z1))
            for x2, y2, z2 in new_s2:
                counter = 0
                for x22, y22, z22 in new_s2:
                    if (x22 - x2, y22 - y2, z22 - z2) in relative_diffs:
                        counter += 1
                # print(counter)
                if counter >= 12:
                    real_s1 = real_xyz[sid1]
                    found = [x1 - x2, y1 - y2, z1 - z2]
                    return (real_s1[0] + found[0], real_s1[1] + found[1],
                            real_s1[2] + found[2]), new_s2
    return None, None


def main():
    input = open('input').read()
    scanners = input.split('\n\n')
    for i, scanner in enumerate(scanners):
        scanner = scanner.splitlines()
        ps = []
        for line in scanner[1:]:
            p = list(map(int, line.split(',')))
            ps.append(p)
        xyz[i] = ps
    real_xyz[0] = (0, 0, 0)
    num_scanners = len(xyz)
    beacons = set()
    for b in xyz[0]:
        beacons.add(tuple(b))
    next_i_list = [0]
    next_j_list = [j for j in range(num_scanners) if j not in real_xyz.keys()]
    while len(real_xyz) != num_scanners:
        new_real_xyz = {}
        for i in next_i_list:
            for j in next_j_list:
                print(i, j)
                real_j, relative_sj = compare(i, j)
                real_sj = []
                if real_j is not None:
                    new_real_xyz[j] = real_j
                    xyz[j] = relative_sj
                    for (x, y, z) in relative_sj:
                        real_sj.append(
                            [real_j[0] + x, real_j[1] + y, real_j[2] + z])
                    print(real_sj)
                    xyz[j] = relative_sj
                    for sj in real_sj:
                        beacons.add(tuple(sj))
        real_xyz.update(new_real_xyz)
        next_i_list = new_real_xyz.keys()
        next_j_list = [
            j for j in range(num_scanners) if j not in real_xyz.keys()
        ]
        print(real_xyz)
    print(len(beacons))


# main()


def part2():
    scanners = {
        0: (0, 0, 0),
        10: (3, -1190, 85),
        16: (-132, 101, -1110),
        18: (-29, 100, 1336),
        6: (-130, -1186, -1064),
        21: (-126, -1215, 1345),
        27: (-1280, -1088, -11),
        31: (-90, -2396, 103),
        7: (31, 6, 2393),
        9: (1088, -3, 1193),
        15: (-96, -2312, -1198),
        30: (1228, -1222, -1207),
        2: (-69, -1046, 2535),
        5: (-1318, -2301, 148),
        33: (-2436, -1184, -11),
        20: (-93, 1233, 2367),
        24: (1219, 87, 2495),
        11: (-1265, -2258, -1148),
        17: (-35, -2295, -2401),
        28: (-87, -3461, -1172),
        8: (-89, -2405, 2516),
        14: (1156, -1192, 2380),
        22: (1077, 1274, 2439),
        26: (-1335, -2272, -2377),
        32: (-1228, -3559, -1170),
        3: (-33, -3507, -2353),
        25: (-70, -2427, -3487),
        4: (1117, -3566, -1042),
        1: (-27, -3490, 2522),
        12: (1104, -1190, 3570),
        29: (2435, -1076, 2433),
        13: (-28, -3544, -3549),
        19: (1182, -2332, 3731),
        23: (1201, -1066, 4912)
    }
    xyzs = scanners.values()
    ans = max([
        abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]) for a in xyzs
        for b in xyzs
    ])
    print(ans)


part2()

