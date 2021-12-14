use std::collections::HashMap;
use std::fs;
fn count_pairs(poly: &str, map: &HashMap<String, &str>, step: usize) -> HashMap<String, u64> {
    let mut counter = HashMap::<String, u64>::new();
    poly.chars()
        .collect::<Vec<char>>()
        .windows(2)
        .for_each(|win| {
            let s = win.iter().collect::<String>();
            *counter.entry(s).or_insert(0) += 1;
        });
    for _ in 0..step {
        let mut new_counter = counter.clone();
        for (k, v) in counter.iter() {
            let middle = map[k];
            let new1 = k[0..1].to_owned() + middle;
            let new2 = middle.to_owned() + &k[1..2];
            *new_counter.entry(new1).or_insert(0) += v;
            *new_counter.entry(new2).or_insert(0) += v;
            *new_counter.get_mut(k).unwrap() -= v;
        }
        counter = new_counter;
    }
    counter
}
fn pairs_to_ans(poly: &str, counter: &HashMap<String, u64>) -> u64 {
    let mut ch_counter: HashMap<char, u64> = HashMap::new();
    for (k, v) in counter.iter() {
        for ch in k.chars() {
            *ch_counter.entry(ch).or_insert(0) += v;
        }
    }
    // all chars count twice except head&tail
    ch_counter.iter_mut().for_each(|(_, v)| *v /= 2);
    *ch_counter.entry(poly.chars().nth(0).unwrap()).or_insert(0) += 1;
    *ch_counter.entry(poly.chars().last().unwrap()).or_insert(0) += 1;
    // compute answer
    let a1 = ch_counter.iter().map(|m| *m.1).max().unwrap();
    let a2 = ch_counter.iter().map(|m| *m.1).min().unwrap();
    a1 - a2
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let mut map: HashMap<String, &str> = HashMap::new();
    let content = content.trim().split("\n\n").collect::<Vec<&str>>();
    for line in content[1].lines() {
        let (l, r) = line.split_once(" -> ").unwrap();
        map.insert(l.to_string(), r);
    }
    // 1
    let poly = content[0].to_string();
    let counter = count_pairs(&poly, &map, 10);
    println!("{}", pairs_to_ans(&poly, &counter));
    // 2
    let counter = count_pairs(&poly, &map, 40);
    println!("{}", pairs_to_ans(&poly, &counter));
}
