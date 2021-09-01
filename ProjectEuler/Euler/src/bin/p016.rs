use num_bigint::BigUint;

fn main() {
    let ans = BigUint::from(2u32).pow(1000) // 2^1000
        .to_string() // string
        .chars().filter_map(|c| c.to_digit(10)) // chars -> digits 
        .sum::<u32>();
    println!("{}", ans);
}