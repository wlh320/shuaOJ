use euler::sieve_of_era;
use std::collections::HashSet;
fn main() {
	let mut set = HashSet::new();
	let limit: u64 = 50_000_000;
	let sqrt_limit = (limit as f64).sqrt() as u64 + 1;
	let is_prime = sieve_of_era(sqrt_limit);
	let primes: Vec<u64> = (1..sqrt_limit).filter(|&x| is_prime[x as usize]).collect();
	for x in primes.iter().filter(|&x| x.pow(2) < limit) {
		for y in primes.iter().filter(|&x| x.pow(3) < limit) {
			for z in primes.iter().filter(|&x| x.pow(4) < limit) {
				let n = x.pow(2) + y.pow(3) + z.pow(4);
				if n < limit {
					set.insert(n);
				}
			}
		}
	}
	println!("{}", set.len());
}
