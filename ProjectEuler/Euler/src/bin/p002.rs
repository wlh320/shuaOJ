use euler::seq::Fib;

fn main() {
    let ans: i32 = Fib(1, 1)
        .take_while(|&x| x < 400_0000)
        .filter(|&x| x % 2 == 0)
        .sum();
    println!("{:?}", ans);
}
