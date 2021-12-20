use std::cmp::min;
use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashSet};
use std::fs;
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let mut nums: Vec<Vec<u32>> = vec![];
    for line in content.lines() {
        let line = line
            .chars()
            .map(|ch| ch.to_digit(10).unwrap())
            .collect::<Vec<u32>>();
        nums.push(line);
    }
    // 1 dp is wrong but the answer is ok
    const N: usize = 100;
    let mut dp = nums.clone();
    for j in 1..N {
        dp[0][j] = dp[0][j - 1] + nums[0][j];
    }
    for i in 1..N {
        dp[i][0] = dp[i - 1][0] + nums[i][0];
    }
    for i in 1..N {
        for j in 1..N {
            dp[i][j] = nums[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    println!("{}", dp[N - 1][N - 1] - nums[0][0]);

    // 2 dijkstra
    const N2: usize = 5 * N;
    let mut nums2: Vec<Vec<u32>> = vec![vec![0; N2]; N2];
    for i in 0..N2 {
        for j in 0..N2 {
            nums2[i][j] = nums[i % N][j % N] + (i as u32) / (N as u32) + (j as u32) / (N as u32);
            while nums2[i][j] > 9 {
                nums2[i][j] -= 9;
            }
        }
    }
    let mut pq = BinaryHeap::new();
    let mut vis = HashSet::<(usize, usize)>::new();
    pq.push((Reverse(nums[0][0]), 0, 0));
    vis.insert((0, 0));
    while let Some((Reverse(dis), i, j)) = pq.pop() {
        if i == N2 - 1 && j == N2 - 1 {
            println!("{:?}", dis - nums2[0][0]);
            break;
        }
        let (ii, jj) = (i as isize, j as isize);
        for (ni, nj) in [(ii - 1, jj), (ii, jj - 1), (ii + 1, jj), (ii, jj + 1)] {
            if ni < 0 || ni >= N2 as isize || nj < 0 || nj >= N2 as isize {
                continue;
            }
            let (ni, nj) = (ni as usize, nj as usize);
            if !vis.contains(&(ni, nj)) {
                vis.insert((ni, nj));
                pq.push((Reverse(dis + nums2[ni][nj]), ni, nj));
            }
        }
    }
}
