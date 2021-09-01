fn solve(n: i32) -> i32 {
    (1..n).filter(|x| x % 3 == 0 || x % 5 == 0).sum()
}
fn main() {
    println!("{}", solve(1000));
}
