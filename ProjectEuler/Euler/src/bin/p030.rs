fn sum_of_fifth_pow(n: u32) -> u32 {
    n.to_string().chars()
    .map(|c| c.to_digit(10).unwrap().pow(5))
    .sum::<u32>()
}

fn main() {
    let ans: u32 = (2..1000_000) // 6*10^5 < 10^6 
        .filter(|&x| x == sum_of_fifth_pow(x))
        .sum();
    println!("{:?}", ans);
}