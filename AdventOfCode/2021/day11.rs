use std::collections::HashSet;
use std::fs;
fn plus_one(board: &mut Vec<Vec<u32>>) {
    board
        .iter_mut()
        .for_each(|line| line.iter_mut().for_each(|n| *n += 1));
}
fn flag(board: &mut Vec<Vec<u32>>) {
    board
        .iter_mut()
        .for_each(|line| line.iter_mut().filter(|n| **n > 9).for_each(|n| *n = 0));
}
fn flash(board: &mut Vec<Vec<u32>>, set: &mut HashSet<(usize, usize)>) {
    let h = board.len();
    let w = board[0].len();
    let di = vec![-1i32, -1, -1, 0, 0, 1, 1, 1];
    let dj = vec![-1i32, 0, 1, -1, 1, -1, 0, 1];
    for i in 0..h {
        for j in 0..w {
            if board[i][j] > 9 && !set.contains(&(i, j)) {
                for (di, dj) in di.iter().zip(dj.iter()) {
                    if (i as i32 + di) < 0
                        || (i as i32 + di) >= h as i32
                        || (j as i32 + dj) < 0
                        || (j as i32 + dj) >= w as i32
                    {
                        continue;
                    }
                    board[(i as i32 + di) as usize][(j as i32 + dj) as usize] += 1;
                }
                set.insert((i, j));
            }
        }
    }
}
fn simulate(board: &mut Vec<Vec<u32>>) -> usize {
    let mut set = HashSet::<(usize, usize)>::new();
    let mut l = 10000;
    while set.len() != l {
        l = set.len();
        flash(board, &mut set);
    }
    flag(board);
    set.len()
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    // 1
    let mut board: Vec<Vec<u32>> = Vec::new();
    for line in content.lines() {
        board.push(line.chars().map(|ch| ch.to_digit(10).unwrap()).collect());
    }
    let mut count = 0usize;
    for _ in 0..100 {
        plus_one(&mut board);
        count += simulate(&mut board);
        flag(&mut board);
    }
    println!("{}", count);

    // 2
    let mut board: Vec<Vec<u32>> = Vec::new();
    for line in content.lines() {
        board.push(line.chars().map(|ch| ch.to_digit(10).unwrap()).collect());
    }
    for i in 1.. {
        plus_one(&mut board);
        let count = simulate(&mut board);
        if count == board.len() * board[0].len() {
            println!("{}", i);
            break;
        }
    }
}
