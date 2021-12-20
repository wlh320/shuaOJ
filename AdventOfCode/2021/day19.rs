use std::collections::{HashMap, HashSet, VecDeque};
use std::fs;
type Scanner = Vec<P>;
fn sign(p: P, angle: u8) -> P {
    let x = if angle >> 2 == 0 { p.0 } else { -p.0 };
    let y = if (angle & 0b010) >> 1 == 0 { p.1 } else { -p.1 };
    let z = if angle & 1 == 0 { p.2 } else { -p.2 };
    P(x, y, z)
}
#[derive(Debug, Hash, PartialEq, Eq, Clone, Copy)]
struct P(isize, isize, isize);
impl P {
    fn rotate(&self, id: u8) -> P {
        // Too stupid to generate 48 rotations without de-duplicating.
        let (x, y, z) = (self.0, self.1, self.2);
        let (angle, axis) = (id / 6, id % 6);
        match axis {
            0 => sign(P(x, y, z), angle),
            1 => sign(P(x, z, y), angle),
            2 => sign(P(y, x, z), angle),
            3 => sign(P(y, z, x), angle),
            4 => sign(P(z, x, y), angle),
            5 => sign(P(z, y, x), angle),
            _ => P(0, 0, 0),
        }
    }
    fn manhattan_distance(&self, other: &P) -> isize {
        (self.0 - other.0).abs() + (self.1 - other.1).abs() + (self.2 - other.2).abs()
    }
}

fn rorate_all(s: &Scanner, id: u8) -> Scanner {
    s.iter().map(|p| p.rotate(id)).collect()
}

fn compare(
    scanners: &Vec<Scanner>,
    id1: usize,
    id2: usize,
    pos: &HashMap<usize, P>,
    beacons: &mut HashSet<P>,
) -> Option<(P, Scanner)> {
    let s1 = &scanners[id1];
    let s2 = &scanners[id2];
    for id in 0..48 {
        let new_s2 = rorate_all(&s2, id);
        for p1 in s1 {
            let diffs: HashSet<_> = s1
                .iter()
                .map(|p| (p.0 - p1.0, p.1 - p1.1, p.2 - p1.2))
                .collect();
            for p2 in new_s2.iter() {
                let counter = new_s2
                    .iter()
                    .map(|p| (p.0 - p2.0, p.1 - p2.1, p.2 - p2.2))
                    .filter(|p| diffs.contains(p))
                    .count();
                if counter >= 12 {
                    let abs_s1 = pos.get(&id1).unwrap();
                    let abs_s2 = P(
                        abs_s1.0 + p1.0 - p2.0,
                        abs_s1.1 + p1.1 - p2.1,
                        abs_s1.2 + p1.2 - p2.2,
                    );
                    for p in new_s2.iter() {
                        beacons.insert(P(p.0 + abs_s2.0, p.1 + abs_s2.1, p.2 + abs_s2.2));
                    }
                    return Some((abs_s2, new_s2));
                }
            }
        }
    }
    None
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let lines: Vec<&str> = content.split("\n\n").collect();
    let mut scanners = vec![];
    for scanner in lines.iter() {
        let beacons: Vec<P> = scanner
            .lines()
            .skip(1)
            .map(|line| {
                let v: Vec<_> = line.split(',').map(|s| s.parse().unwrap()).collect();
                P(v[0], v[1], v[2])
            })
            .collect();
        scanners.push(beacons);
    }
    let mut pos = HashMap::<usize, P>::new();
    let mut q = VecDeque::new();
    let mut beacons: HashSet<P> = scanners[0].clone().into_iter().collect();
    q.push_back(0);
    pos.insert(0, P(0, 0, 0));
    while let Some(i) = q.pop_front() {
        if pos.len() == scanners.len() {
            break;
        }
        for j in 0..scanners.len() {
            if !pos.contains_key(&j) {
                if let Some((p, abs_beacons)) = compare(&scanners, i, j, &pos, &mut beacons) {
                    pos.entry(j).or_insert(p);
                    scanners[j] = abs_beacons;
                    q.push_back(j);
                }
            }
        }
        println!("Found {} scanners", pos.len());
    }
    // 1
    println!("{}", beacons.len());
    // 2
    let dis = pos
        .values()
        .map(|a| pos.values().map(|b| a.manhattan_distance(b)).max().unwrap())
        .max()
        .unwrap();
    println!("{}", dis);
}
