fn main() {
	let p_lim = 1_000_000_000;
	let s_lim = p_lim / 3 + 2;
	let mut ans = 0;
	for a in (1u64..=s_lim).step_by(2) { // S = b*sqrt(4a^2-b^2)/4, b=a+1 or b=a-1 => a is odd
		for b in [a + 1, a - 1].iter().filter(|&&x| x > 0 && a + a > x) {
			let x = 4 * a * a - b * b;
			let xroot = (x as f64).sqrt() as u64;
			if xroot * xroot == x && (b * xroot) % 4 == 0 {
				ans += 2 * a + b;
			}
		}
	}
	println!("{}", ans);
}
