use std::collections::HashSet;
use std::fs;

fn fold(p: &mut HashSet<(usize, usize)>, ins: &[(usize, usize)]) {
    let mut w = 2000usize;
    let mut h = 2000usize;
    for (pos_x, pos_y) in ins {
        match (pos_x, pos_y) {
            (pos, 0) => {
                let mut new_p = HashSet::<(usize, usize)>::new();
                for (x, y) in p.iter() {
                    if pos * 2 >= *x {
                        new_p.insert((pos * 2 - *x, *y));
                    }
                }
                p.extend(&new_p);
                w = *pos;
            }
            (0, pos) => {
                let mut new_p = HashSet::<(usize, usize)>::new();
                for (x, y) in p.iter() {
                    if pos * 2 >= *y {
                        new_p.insert((*x, pos * 2 - *y));
                    }
                }
                p.extend(&new_p);
                h = *pos;
            }
            _ => (),
        }
    }
    for y in 0..h {
        for x in 0..w {
            print!("{}", if p.contains(&(x, y)) { "#" } else { " " });
        }
        println!();
    }
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let content = content.trim().split("\n\n").collect::<Vec<&str>>();
    let mut p: HashSet<(usize, usize)> = HashSet::new();
    let mut ins: Vec<(usize, usize)> = vec![];
    for line in content[0].lines() {
        let (x, y) = line.trim().split_once(',').unwrap();
        p.insert((x.parse().unwrap(), y.parse().unwrap()));
    }
    for line in content[1].lines() {
        let (_, i) = line.split_once("along ").unwrap();
        match i.split_once('=').unwrap() {
            ("x", pos) => ins.push((pos.parse().unwrap(), 0)),
            ("y", pos) => ins.push((0, pos.parse().unwrap())),
            _ => (),
        }
    }
    // 1 x=655
    let mut new_set = HashSet::<(usize, usize)>::new();
    for (x, y) in p.iter() {
        new_set.insert((655 * 2 - *x, *y));
    }
    p.extend(&new_set);
    let mut ans = 0;
    for x in 0..655 {
        for y in 0..2000 {
            if p.contains(&(x, y)) {
                ans += 1;
            }
        }
    }
    println!("{}", ans);

    // 2 do next
    fold(&mut p, &ins[1..]);
}
