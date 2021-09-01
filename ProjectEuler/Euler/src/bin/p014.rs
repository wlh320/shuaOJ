use euler::seq::Collatz;

fn main() {
    let ans: u32 = (1..100_0000).max_by_key(|x| Collatz(*x).count()).unwrap();
    println!("{}", ans);
}
