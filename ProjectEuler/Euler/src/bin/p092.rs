use std::collections::HashMap;

fn square_digit_sum(n: i32) -> i32 {
    if n < 10 {
        n.pow(2)
    } else {
        square_digit_sum(n / 10) + (n % 10).pow(2)
    }
}

fn to_chain_end(map: &mut HashMap<i32, i32>, n: i32) -> i32 {
    if let Some(&v) = map.get(&n) {
        return v;
    }
    let ans = to_chain_end(map, square_digit_sum(n));
    map.insert(n, ans);
    return ans;
}

fn main() {
    let mut map = HashMap::new();
    map.insert(1, 1);
    map.insert(89, 89);
    let ans = (1..1000_0000)
        .map(|n| to_chain_end(&mut map, n))
        .filter(|&n| n == 89)
        .count();
    println!("{}", ans);
}
