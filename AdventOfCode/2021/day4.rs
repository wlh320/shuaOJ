use std::fs;
fn is_win(bstate: &Vec<Vec<i32>>) -> bool {
    let n = bstate[0].len();
    let line_ok = bstate.iter().any(|line| line.iter().all(|&v| v == 1));
    let col_ok = (0..n).any(|j| (0..n).all(|i| bstate[i][j] == 1));
    line_ok || col_ok
}

fn flag(bstate: &mut Vec<Vec<i32>>, board: &Vec<Vec<i32>>, x: i32) {
    let n = bstate[0].len();
    for i in 0..n {
        for j in 0..n {
            if board[i][j] == x {
                bstate[i][j] = 1;
            }
        }
    }
}

fn play(nums: &Vec<i32>, board: &Vec<Vec<i32>>) -> Option<(usize, i32)> {
    let n = board[0].len();
    let mut bstate = vec![vec![0; n]; n];
    for i in 0..nums.len() {
        flag(&mut bstate, board, nums[i]);
        if is_win(&bstate) {
            let sum: i32 = (0..n)
                .map(|i| {
                    (0..n)
                        .map(|j| if bstate[i][j] == 0 { board[i][j] } else { 0 })
                        .sum::<i32>()
                })
                .sum();
            return Some((i, sum));
        }
    }
    None
}

fn main() {
    let content = fs::read_to_string("input1").unwrap();
    let lines: Vec<&str> = content.lines().collect();
    let nums: Vec<i32> = lines[0]
        .split(',')
        .map(|s| s.parse::<i32>().unwrap())
        .collect();
    let mut win_states: Vec<(usize, i32)> = vec![];
    lines
        .iter()
        .skip(1)
        .collect::<Vec<&&str>>()
        .chunks(6)
        .for_each(|win| {
            let board: Vec<Vec<i32>> = win
                .into_iter()
                .skip(1)
                .map(|line| {
                    line.split_whitespace()
                        .map(|s| s.parse::<i32>().unwrap())
                        .collect::<Vec<i32>>()
                })
                .collect();
            if let Some(v) = play(&nums, &board) {
                win_states.push(v);
            }
        });
    // 1
    let idx = win_states.iter().min_by_key(|v| v.0).unwrap();
    println!("{}", nums[idx.0] * idx.1);
    // 2
    let idx = win_states.iter().max_by_key(|v| v.0).unwrap();
    println!("{}", nums[idx.0] * idx.1);
}