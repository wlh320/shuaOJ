use std::fs;
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let lines: Vec<(&str, i32)> = content
        .lines()
        .map(|line| line.split_once(' ').unwrap())
        .map(|(d, v)| (d, v.parse().unwrap()))
        .collect();

    // 1
    let mut x = 0;
    let mut y = 0;
    for (d, v) in lines.iter() {
        match *d {
            "up" => x -= v,
            "down" => x += v,
            "forward" => y += v,
            _ => {}
        }
    }
    println!("{}", x * y);

    // 2
    let mut x = 0;
    let mut y = 0;
    let mut aim = 0;
    for (d, v) in lines.iter() {
        match *d {
            "up" => aim -= v,
            "down" => aim += v,
            "forward" => {
                y += v;
                x += aim * v;
            }
            _ => {}
        }
    }
    println!("{}", x * y);
}
