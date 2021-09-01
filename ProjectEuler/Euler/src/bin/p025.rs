use euler::seq::Fib;
use num_bigint::BigUint;

fn main() {
    let ans = Fib(BigUint::from(0u32), BigUint::from(1u32))
        .enumerate()
        .find(|(_, n)| n.to_string().len() == 1000)
        .unwrap().0 + 1;
    println!("{}", ans);
}
