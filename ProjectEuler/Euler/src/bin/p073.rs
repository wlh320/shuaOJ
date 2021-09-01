fn gcd(a: u32, b: u32) -> u32 {
	if a % b == 0 {
		b
	} else {
		gcd(b, a % b)
	}
}
fn main() {
	let mut ans = 0;
	for n in 1u32..6000 {
		for d in 2 * n + 1..3 * n {
			let g = gcd(n, d);
			if d <= 12000 && g == 1{
				ans += 1;
			}
		}
	}
	println!("{}", ans);
}
