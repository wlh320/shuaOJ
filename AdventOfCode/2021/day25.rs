use std::collections::HashMap;
use std::fs;
// fn print_map(map: &HashMap<(usize, usize), char>, h: usize, w: usize) {
//     for i in 0..h {
//         for j in 0..w { // right move first
//             if let Some(ch) = map.get(&(i, j)) {
//                 print!("{}", ch);
//             } else {
//                 print!(".");
//             }
//         }
//         println!();
//     }
//     println!();
// }
fn move_cucumber(
    map: &HashMap<(usize, usize), char>,
    h: usize,
    w: usize,
) -> HashMap<(usize, usize), char> {
    let mut next = HashMap::new();
    // move east
    for i in 0..h {
        for j in (0..w).rev() {
            // right move first
            if let Some('>') = map.get(&(i, j)) {
                let nj = (j + 1) % w;
                if !map.contains_key(&(i, nj)) {
                    next.insert((i, nj), '>');
                } else {
                    next.insert((i, j), '>');
                }
            }
        }
    }
    // move south
    for i in (0..h).rev() {
        // bottom move first
        for j in 0..w {
            if let Some('v') = map.get(&(i, j)) {
                let ni = (i + 1) % h;
                if !next.contains_key(&(ni, j)) && !matches!(map.get(&(ni, j)), Some('v')) {
                    next.insert((ni, j), 'v');
                } else {
                    next.insert((i, j), 'v');
                }
            }
        }
    }
    next
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let mut map = HashMap::new();
    let (mut h, mut w) = (0, 0);
    for (i, line) in content.lines().enumerate() {
        for (j, ch) in line.chars().enumerate() {
            if ch == '>' || ch == 'v' {
                map.insert((i, j), ch);
            }
            w = j + 1;
        }
        h = i + 1;
    }
    for i in 1.. {
        let next = move_cucumber(&map, h, w);
        if map == next {
            println!("{}", i);
            break;
        }
        map = next;
    }
}
