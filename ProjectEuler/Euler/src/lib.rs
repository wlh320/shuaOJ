pub mod seq;

pub fn is_prime(n: u64) -> bool {
    if n <= 1 {
        false
    } else {
        !(2..n).take_while(|x| x * x <= n).any(|x| n % x == 0)
    }
}

pub fn sieve_of_era(n: u64) -> Vec<bool> {
	let mut ans = vec![true; (n + 1) as usize];
	ans[0] = false;
	ans[1] = false;
	for num in (2..=n).take_while(|x| x * x <= n) {
		if ans[num as usize] {
			for v in (2 * num..=n).step_by(num as usize) {
				ans[v as usize] = false;
			}
		}
	}
    ans
}

pub fn sieve_phi(n: u64) -> Vec<u64> {
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

pub fn to_digit_counter(mut n: u64) -> [u8; 10] {
	let mut ans: [u8; 10] = [0; 10];
	while n != 0 {
		ans[(n%10) as usize] += 1;
		n /= 10;
	}
	ans
}