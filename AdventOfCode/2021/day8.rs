use std::collections::HashMap;
use std::fs;

fn analyze(left_nums: &mut Vec<&str>) -> Vec<String> {
    let mut map = HashMap::<char, char>::new();
    let mut counter: HashMap<char, i32> = HashMap::new();
    let (mut num1, mut num4, mut num7) = ("", "", "");
    for num in left_nums.iter() {
        num.chars()
            .for_each(|c| *counter.entry(c).or_insert(0) += 1);
        match num.len() {
            2 => num1 = num,
            3 => num7 = num,
            4 => num4 = num,
            _ => (),
        }
    }
    for (ch, n) in counter.iter() {
        match n {
            4 => map.insert(*ch, 'e'),
            6 => map.insert(*ch, 'b'),
            9 => map.insert(*ch, 'f'),
            8 => map.insert(*ch, 'c'), // another is 'a'
            7 => map.insert(*ch, 'g'), // another is 'd'
            _ => None,
        };
    }
    // determine 'a', compare 'cf' and 'acf'
    for ch in num7.chars() {
        if let None = num1.chars().find(|c| c == &ch) {
            map.insert(ch, 'a');
        }
    }
    // determine 'd', compare 'cf' and 'bcdf
    for ch in num4.chars() {
        if let None = num1.chars().find(|c| c == &ch) {
            // b or d
            if let Some('g') = map.get(&ch) {
                // exclude b
                map.insert(ch, 'd');
            }
        }
    }
    let mut imap = HashMap::<char, char>::new(); // inverse map
    for (k, v) in map.iter() {
        imap.insert(*v, *k);
    }
    let segs: Vec<&str> = vec![
        "abcefg", "cf", "acdeg", "acdfg", "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg",
    ];
    (0..=9)
        .map(|i| segs[i].chars().map(|ch| imap[&ch]).collect::<String>())
        .map(|s| {
            let mut chars: Vec<char> = s.chars().collect();
            chars.sort();
            String::from_iter(chars.iter())
        })
        .collect()
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let mut ans = 0;
    // 1
    for line in content.lines() {
        let (_, right) = line.split_once(" | ").unwrap();
        let right_nums: Vec<&str> = right.trim().split(' ').collect();
        for num in right_nums {
            match num.len() {
                2 | 3 | 4 | 7 => ans += 1,
                _ => (),
            };
        }
    }
    println!("{}", ans);
    // 2
    let mut ans = 0;
    for line in content.lines() {
        let (left, right) = line.split_once(" | ").unwrap();
        let mut left_nums: Vec<&str> = left.trim().split(' ').collect();
        let right_nums: Vec<&str> = right.trim().split(' ').collect();
        let map = analyze(&mut left_nums);
        let mut n = 0;
        for right in right_nums {
            let mut right_chars: Vec<char> = right.chars().collect();
            right_chars.sort();
            let target = String::from_iter(right_chars.iter());
            let idx = map.iter().position(|r| r == &target).unwrap();
            n *= 10;
            n += idx;
        }
        ans += n;
    }
    println!("{}", ans);
}
