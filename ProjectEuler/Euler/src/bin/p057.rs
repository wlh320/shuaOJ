use num_bigint::BigUint;
fn main() {
	let (mut a, mut b) = (BigUint::from(0u32), BigUint::from(1u32));
	let mut ans = 0;
	for _ in 0..1000 {
		let temp = b.clone();
		b = b * 2u32 + &a;
		a = temp;
		if (&a+&b).to_string().len() > b.to_string().len() {
			ans += 1;
		}
	}
	println!("{}", ans);
}