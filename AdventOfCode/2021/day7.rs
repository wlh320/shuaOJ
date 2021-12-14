use std::fs;
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let nums: Vec<i32> = content
        .trim()
        .split(',')
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    // 1
    let max = nums.iter().max().unwrap();
    let ans = (0..=*max)
        .map(|level| nums.iter().map(|n| (n - level).abs()).sum::<i32>())
        .min()
        .unwrap();
    println!("{}", ans);

    // 2
    let max = nums.iter().max().unwrap();
    let ans = (0..=*max)
        .map(|level| {
            nums.iter()
                .map(|n| {
                    let x = (n - level).abs();
                    x * (x + 1) / 2
                })
                .sum::<i32>()
        })
        .min()
        .unwrap();
    println!("{}", ans);
}
