use std::collections::VecDeque;
use std::fs;
fn main() {
    const H: usize = 100; // height
    const W: usize = 100; // width
    let content = fs::read_to_string("input").unwrap();
    let mut board: Vec<Vec<u32>> = vec![vec![0; W]; H];
    for (i, line) in content.lines().enumerate() {
        board[i] = line.chars().map(|c| c.to_digit(10).unwrap()).collect();
    }
    let mut low_points: Vec<(usize, usize)> = vec![];
    let mut ans = 0;
    for i in 0..H {
        for j in 0..W {
            let up = if i == 0 { true } else {board[i][j] < board[i-1][j]};
            let down = if i == H-1 { true } else {board[i][j] < board[i+1][j]};
            let left = if j == 0 { true } else {board[i][j] < board[i][j-1]};
            let right = if j == W-1 { true } else {board[i][j] < board[i][j+1]};
            if left && right && up && down {
                ans += board[i][j] + 1;
                low_points.push((i, j));
            }
        }
    }
    println!("{}", ans);
    // 2
    let mut sizes: Vec<i32> = vec![];
    for (i, j) in low_points {
        let mut vis: Vec<Vec<bool>> = vec![vec![false; 100]; 100];
        let mut count = 0;
        let mut q = VecDeque::<(usize, usize)>::new();
        q.push_back((i, j));
        vis[i][j] = true;
        let di = vec![1, -1, 0, 0];
        let dj = vec![0, 0, 1, -1];
        while !q.is_empty() {
            let (i, j) = q.pop_front().unwrap();
            count += 1;
            for (di, dj) in di.iter().zip(dj.iter()) {
                let ni_i32 = i as i32 + *di;
                let nj_i32 = j as i32 + *dj;
                if ni_i32 < 0 || nj_i32 < 0 {
                    continue;
                }
                let ni = ni_i32 as usize;
                let nj = nj_i32 as usize;
                if ni >= H || nj >= W || board[ni][nj] >= 9 || vis[ni][nj] {
                    continue;
                }
                if board[ni][nj] > board[i][j] {
                    vis[ni][nj] = true;
                    q.push_back((ni, nj));
                }
            }
        }
        sizes.push(count as i32);
    }
    sizes.sort_by_key(|x| -x);
    println!("{:?}", sizes[0] * sizes[1] * sizes[2]);
}
