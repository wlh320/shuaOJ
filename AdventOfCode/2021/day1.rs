use std::fs::File;
use std::io::{self, BufRead};
fn main() {
    let file = File::open("input").unwrap();
    let lines = io::BufReader::new(file).lines();
    let v: Vec<i32> = lines
        .map(|line| line.unwrap().trim().parse().unwrap())
        .collect();
    // 1
    let ans = v
        .iter()
        .zip(v.iter().skip(1))
        .filter(|(&a, &b)| a < b)
        .count();
    println!("{}", ans);
    // 2
    let v: Vec<i32> = v.windows(3).map(|win| win.iter().sum()).collect();
    let ans = v
        .iter()
        .zip(v.iter().skip(1))
        .filter(|(&a, &b)| a < b)
        .count();
    println!("{}", ans);
}
