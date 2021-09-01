use num_bigint::BigUint;

fn digit_sum(a: u32, b: u32) -> u32 {
    BigUint::from(a)
        .pow(b)
        .to_string()
        .chars()
        .map(|c| c.to_digit(10).unwrap())
        .sum::<u32>()
}

fn main() {
    let ans = (1..100)
        .flat_map(|a| (1..100).map(move |b| digit_sum(a, b)))
        .max()
        .unwrap();
    println!("{}", ans);
}
