use euler::is_prime;

fn main() {
    let n = 10001;
    let ans = (1..).filter(|&x| is_prime(x)).nth(n - 1).unwrap();
    println!("{}", ans);
}
