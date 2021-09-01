use euler::is_prime;

fn main() {
    let mut cnt_prime = 0;
    let mut cnt_all = 1;
    let ans = (3..).step_by(2)
        .find(|&len| {
            let step = len - 1;
            cnt_prime += (len * len - step * 3..=len * len).step_by(step)
                .filter(|&x| is_prime(x as u64))
                .count();
            cnt_all += 4;
            10 * cnt_prime < cnt_all
        })
        .unwrap();
    println!("{}", ans);
}
