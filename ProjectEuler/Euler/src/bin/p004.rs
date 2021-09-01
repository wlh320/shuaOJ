fn is_palindrome(x: i32, len: u32) -> bool {
    if len <= 1 {
        return true;
    } else {
        let l = x % 10;
        let h = x / 10i32.pow(len - 1);
        let new_x = (x - h * 10i32.pow(len - 1)) / 10;
        return l == h && is_palindrome(new_x, len - 2);
    }
}

fn main() {
    let mut ans = 0;
    for x in 100..=999 {
        for y in 100..=999 {
            let num = x * y;
            let len = (1..).find(|&v| num / 10i32.pow(v) == 0).unwrap_or(0);
            if is_palindrome(num, len) {
                ans = std::cmp::max(ans, num);
            }
        }
    }
    println!("{}", ans);
}
