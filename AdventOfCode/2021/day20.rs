use std::collections::HashSet;
use std::fs;

fn enhance_pixel(set: &HashSet<(isize, isize)>, pat: &str, i: isize, j: isize) -> bool {
    let di = vec![-1, -1, -1, 0, 0, 0, 1, 1, 1];
    let dj = vec![-1, 0, 1, -1, 0, 1, -1, 0, 1];
    let mut idx = 0;
    for (di, dj) in di.iter().zip(dj.iter()) {
        let ii = i + di;
        let jj = j + dj;
        idx <<= 1;
        if set.contains(&(ii, jj)) {
            idx += 1;
        }
    }
    pat.chars().nth(idx) == Some('#')
}

fn enhance(
    set: HashSet<(isize, isize)>,
    pat: &str,
    step: isize,
    h: isize,
    w: isize,
) -> HashSet<(isize, isize)> {
    let mut next: HashSet<(isize, isize)> = HashSet::new();
    let bb = 100; // add large border (stupid way to handle flipping of border pixels)
    for i in 0 - step - bb..h + step + bb {
        for j in 0 - step - bb..w + step + bb {
            if enhance_pixel(&set, pat, i, j) {
                next.insert((i, j));
            }
        }
    }
    next
}

fn run(set: &HashSet<(isize, isize)>, pat: &str, h: isize, w: isize, limit: isize) {
    let mut set = set.clone();
    for step in 1..=limit {
        set = enhance(set, pat, step, h, w);
    }
    let ans = set
        .into_iter()
        .filter(|(i, j)| *i >= 0 - limit && *i < h + limit && *j >= 0 - limit && *j < w + limit)
        .count();
    println!("{}", ans);
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let (pat, input) = content.split_once("\n\n").unwrap();
    let mut set: HashSet<(isize, isize)> = HashSet::new();
    let mut h = 0;
    let mut w = 0;
    for (i, line) in input.lines().enumerate() {
        for (j, ch) in line.chars().enumerate() {
            w = std::cmp::max(w, j + 1);
            if ch == '#' {
                set.insert((i as isize, j as isize));
            }
        }
        h = std::cmp::max(h, i + 1);
    }
    let (h, w) = (h as isize, w as isize);
    // 1
    run(&set, pat, h, w, 2);
    // 2
    run(&set, pat, h, w, 50);
}
