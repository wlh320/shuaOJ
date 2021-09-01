fn count_divisors(n: u64) -> usize {
    2 * (1..=n).take_while(|x| x * x <= n).filter(|x| n % x == 0).count()
}

fn main() {
    let ans = (1..).scan(0, |acc, x| {
            *acc = *acc + x;
            Some(*acc)
        })
        .find(|&x| count_divisors(x) > 500).unwrap();
    println!("{:?}", ans);
}