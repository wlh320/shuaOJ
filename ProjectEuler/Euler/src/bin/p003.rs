use euler::is_prime;

fn main() {
    let n = 600851475143u64;
    let ans = (2..n)
        .take_while(|x| x * x <= n)
        .filter(|x| n % x == 0)
        .filter(|&x| is_prime(x))
        .max()
        .unwrap();
    println!("{}", ans);
}
