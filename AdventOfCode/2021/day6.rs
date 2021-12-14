use std::fs;
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let nums: Vec<i32> = content
        .trim()
        .split(',')
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    // 1 simulate
    let mut fish = nums.clone();
    for _ in 0..80 {
        let len = fish.len();
        for i in 0..len {
            if fish[i] == 0 {
                fish[i] = 6;
                fish.push(8);
            } else {
                fish[i] -= 1;
            }
        }
    }
    println!("{}", fish.len());

    // 2 dp
    const TGT_DAY: usize = 256;
    let mut dp = vec![vec![0u64; 9]; TGT_DAY + 1];
    for n in nums {
        dp[0][n as usize] += 1;
    }
    for day in 1..=TGT_DAY {
        for n in 0..8 {
            dp[day][n] = dp[day - 1][n + 1];
        }
        dp[day][8] = dp[day - 1][0]; // new born
        dp[day][6] += dp[day - 1][0]; // reset
    }
    println!("{}", dp[TGT_DAY].iter().sum::<u64>());
}
