use num_bigint::BigUint;
use std::collections::HashSet;

fn main() {
    let mut set = HashSet::new();
    for a in 2..=100 {
        for b in 2..=100 {
            set.insert(BigUint::from(a as u32).pow(b));
        }
    }
    println!("{}", set.len());
}