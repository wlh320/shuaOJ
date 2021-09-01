use euler::is_prime;

fn main() {
    let n = 200_0000;
    let ans: u64 = (1u64..n).filter(|&x| is_prime(x)).sum();
    println!("{}", ans);
}
