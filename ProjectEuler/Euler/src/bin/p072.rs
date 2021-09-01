fn sieve_phi(n: u64) -> Vec<u64> {
	let mut phi: Vec<u64> = (0..=n).collect();
	for num in 2..=n {
		if phi[num as usize] == num {
			for v in (num..=n).step_by(num as usize) {
				phi[v as usize] = phi[v as usize] / num * (num - 1);
			}
		}
	}
	phi
}
fn main() {
	let n = 1_000_000;
	let phi = sieve_phi(n);
	let mut ans: u64 = 0;
	for deno in 2u64..=n {
		ans += phi[deno as usize];
	}
	println!("{}", ans);
}
