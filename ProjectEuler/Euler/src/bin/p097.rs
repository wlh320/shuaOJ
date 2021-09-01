fn modpow(n: u128, exp: u128, m: u128) -> u128 {
    if exp == 0 {
        1
    } else if exp % 2 == 0 {
        let tmp = modpow(n, exp / 2, m);
        (tmp * tmp) % m
    } else {
        (n * modpow(n, exp - 1, m)) % m
    }
}

fn main() {
    let pow = modpow(2, 7830457, 10u128.pow(10));
    let ans = (pow * 28433) % 10u128.pow(10) + 1;
    println!("{}", ans);
}
