use std::fs;
fn part1(lines: &Vec<&str>) {
    let len = lines[0].len();
    let mut x = 0;
    let mut y = 0;
    for i in 0..len {
        let count0 = lines.iter().filter(|&&line| &line[i..i + 1] == "0").count();
        let count1 = lines.len() - count0;
        let f = if count0 > count1 { 0 } else { 1 };
        x = (x << 1) + f;
        y = (y << 1) + (1 - f);
    }
    println!("{}", x * y);
}

fn count_freq(lines: &Vec<&str>, idxes: &Vec<usize>) -> (Vec<usize>, Vec<usize>) {
    let len = lines[0].len();
    let mut count0 = vec![0; len];
    let mut count1 = vec![0; len];
    for i in 0..len {
        let c0 = idxes
            .iter()
            .filter(|&&idx| &lines[idx][i..i + 1] == "0")
            .count();
        count0[i] = c0;
        count1[i] = lines.len() - c0;
    }
    (count0, count1)
}

fn part2(lines: &Vec<&str>) {
    let mut candidates: Vec<usize> = (0..lines.len()).collect();
    let mut i = 0;
    while candidates.len() != 1 {
        let (count0, count1) = count_freq(&lines, &candidates);
        let target = if count1[i] >= count0[i] { "1" } else { "0" };
        candidates = candidates
            .into_iter()
            .filter(|&x| &lines[x][i..i + 1] == target)
            .collect();
        i += 1;
    }
    let o2 = i32::from_str_radix(lines[candidates[0]], 2).unwrap();

    let mut candidates: Vec<usize> = (0..lines.len()).collect();
    let mut i = 0;
    while candidates.len() != 1 {
        let (count0, count1) = count_freq(&lines, &candidates);
        let target = if count1[i] >= count0[i] { "0" } else { "1" };
        candidates = candidates
            .into_iter()
            .filter(|&x| &lines[x][i..i + 1] == target)
            .collect();
        i += 1;
    }
    let co2 = i32::from_str_radix(lines[candidates[0]], 2).unwrap();
    println!("{}", o2 * co2);
}

fn main() {
    let content = fs::read_to_string("input").unwrap();
    let lines: Vec<&str> = content.lines().collect();
    part1(&lines);
    part2(&lines);
}
