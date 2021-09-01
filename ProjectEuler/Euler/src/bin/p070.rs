use euler::{sieve_phi, to_digit_counter};

fn is_permutation_pair(a: u64, b: u64) -> bool {
    to_digit_counter(a) == to_digit_counter(b)
}

fn main() {
    let phi = sieve_phi(10u64.pow(7));
    let ans = phi.iter()
        .enumerate()
        .skip(2)
        .filter(|&(n, &p)| is_permutation_pair(n as u64, p))
        .min_by(|&(n1, &p1), &(n2, &p2)| ((n1 as u64) * p2).cmp(&((n2 as u64) * p1)))
        .unwrap();
    println!("{}", ans.0);
}
