use std::collections::HashMap;
fn play1(p1: i32, p2: i32) -> i32 {
    let mut dice = 1;
    let mut s = vec![0, 0];
    let mut pos = vec![p1, p2];
    for i in 0.. {
        pos[i % 2] = pos[i % 2] + dice + dice + 1 + dice + 2;
        while pos[i % 2] > 10 {
            pos[i % 2] -= 10;
        }
        s[i % 2] += pos[i % 2];
        dice += 3;
        if s[i % 2] >= 1000 {
            return s[(i + 1) % 2] * (i as i32 + 1) * 3;
        }
    }
    0
}

fn dfs(
    roll: &HashMap<usize, u64>,
    sum: &mut Vec<u64>,
    pos1: usize,
    pos2: usize,
    count1: u64,
    count2: u64,
    score1: usize,
    score2: usize,
) {
    for (dice1, c1) in roll.iter() {
        let mut next_pos1 = pos1 + dice1;
        while next_pos1 > 10 {
            next_pos1 -= 10;
        }
        let next_score1 = score1 + next_pos1;
        let next_count1 = count1 * c1;
        // p1 win
        if next_score1 >= 21 {
            sum[0] += next_count1 * count2;
        } else {
            for (dice2, c2) in roll.iter() {
                let mut next_pos2 = pos2 + dice2;
                while next_pos2 > 10 {
                    next_pos2 -= 10;
                }
                let next_score2 = score2 + next_pos2;
                let next_count2 = count2 * c2;
                // p2 win
                if next_score2 >= 21 {
                    sum[1] += next_count1 * next_count2;
                } else {
                    // next_round
                    dfs(
                        roll,
                        sum,
                        next_pos1,
                        next_pos2,
                        next_count1,
                        next_count2,
                        next_score1,
                        next_score2,
                    );
                }
            }
        }
    }
}

fn play2(p1: usize, p2: usize) -> u64 {
    let mut roll = HashMap::<usize, u64>::new();
    for i in 1..=3 {
        for j in 1..=3 {
            for k in 1..=3 {
                *roll.entry(i + j + k).or_insert(0) += 1;
            }
        }
    }
    let mut sum = vec![0u64, 0];
    dfs(&roll, &mut sum, p1, p2, 1, 1, 0, 0);
    sum.into_iter().max().unwrap()
}

fn main() {
    // 1
    println!("{}", play1(7, 6));
    // 2
    println!("{}", play2(7, 6));
}
