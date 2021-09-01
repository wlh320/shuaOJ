fn gcd(a: u64, b: u64) -> u64 {
    if a % b == 0 {
        b
    } else {
        gcd(b, a % b)
    }
}

fn lcm(a: u64, b: u64) -> u64 {
    return a * b / gcd(a, b);
}

fn main() {
    // brute force
    // let ans = (1..).find(|&x| (1..=20).all(|v| x % v == 0)).unwrap();

    // lcm
    let ans = (1..=20).fold(1, |val, x| lcm(val, x));
    println!("{}", ans);
}
