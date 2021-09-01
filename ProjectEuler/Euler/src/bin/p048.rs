use num_bigint::BigUint;
use num_traits::ToPrimitive;

fn main() {
    let modulo = 10u64.pow(10);
    let ans = (1u32..=1000)
        .map(|x| {
            BigUint::from(x)
                .modpow(&BigUint::from(x), &BigUint::from(modulo))
                .to_u64()
                .unwrap()
        })
        .fold(0, |acc, x| (acc + x) % modulo);
    println!("{:?}", ans);
}
