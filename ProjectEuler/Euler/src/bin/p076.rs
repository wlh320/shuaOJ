fn main() {
	let mut dp = vec![0; 101];
	dp[0] = 1;
	for i in 1..100 {
		for j in i..=100 {
			dp[j] += dp[j - i];
		}
	}
	println!("{}", dp[100]);
}