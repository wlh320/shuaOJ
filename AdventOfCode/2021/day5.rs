use std::cmp::{max, min};
use std::fs;
fn count(content: &str, diagonal: i32) {
    let mut board = vec![vec![0; 1000]; 1000];
    for line in content.lines() {
        let words = line.split(" -> ").collect::<Vec<&str>>();
        let (c1, c2) = (
            words[0].split_once(',').unwrap(),
            words[1].split_once(',').unwrap(),
        );
        let (x1, y1): (i32, i32) = (c1.0.parse().unwrap(), c1.1.parse().unwrap());
        let (x2, y2): (i32, i32) = (c2.0.parse().unwrap(), c2.1.parse().unwrap());
        if x1 == x2 {
            for y in min(y1, y2)..=max(y1, y2) {
                board[x1 as usize][y as usize] += 1;
            }
        } else if y1 == y2 {
            for x in min(x1, x2)..=max(x1, x2) {
                board[x as usize][y1 as usize] += 1;
            }
        } else {
            let mut x = x1;
            let mut y = y1;
            let dx = if x1 < x2 { 1 } else { -1 };
            let dy = if y1 < y2 { 1 } else { -1 };
            while !(x == x2 && y == y2) {
                board[x as usize][y as usize] += diagonal;
                x += dx;
                y += dy;
            }
            board[x2 as usize][y2 as usize] += diagonal;
        }
    }
    let mut ans = 0;
    for i in 0..board.len() {
        for j in 0..board[0].len() {
            if board[i][j] >= 2 {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    // 1
    count(&content, 0);
    // 2
    count(&content, 1);
}
