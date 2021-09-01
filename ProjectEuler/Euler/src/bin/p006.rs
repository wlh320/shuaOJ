fn main() {
    let ans: i32 = (1..=100)
        .flat_map(|x| (x + 1..=100).map(move |y| 2 * x * y))
        .sum();
    println!("{:?}", ans);
}
