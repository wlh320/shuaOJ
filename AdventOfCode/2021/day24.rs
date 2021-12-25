use std::collections::HashMap;
use std::fs;
fn get<'a>(map: &mut HashMap<&'a str, i32>, v: &'a str) -> i32 {
    if let Ok(x) = v.parse::<i32>() {
        x
    } else {
        *map.entry(v).or_insert(0)
    }
}

fn run(prog: &str, z: i32, w: i32) -> i32 {
    let mut map = HashMap::<&str, i32>::new();
    map.entry("z").or_insert(z);
    map.entry("w").or_insert(w);
    for line in prog.lines() {
        let line = line.split(' ').collect::<Vec<_>>();
        match line.len() {
            3 => {
                let (cmd, a, b) = (line[0], line[1], line[2]);
                match cmd {
                    "add" => {
                        let av = *map.entry(a).or_insert(0);
                        *map.get_mut(a).unwrap() = av + get(&mut map, b);
                    }
                    "mul" => {
                        let av = *map.entry(a).or_insert(0);
                        *map.get_mut(a).unwrap() = av * get(&mut map, b);
                    }
                    "div" => {
                        let av = *map.entry(a).or_insert(0);
                        *map.get_mut(a).unwrap() = av / get(&mut map, b);
                    }
                    "mod" => {
                        let av = *map.entry(a).or_insert(0);
                        *map.get_mut(a).unwrap() = av % get(&mut map, b);
                    }
                    "eql" => {
                        let av = *map.entry(a).or_insert(0);
                        *map.get_mut(a).unwrap() = if av == get(&mut map, b) { 1 } else { 0 };
                    }
                    _ => (),
                }
            }
            _ => (),
        }
    }
    *map.get("z").unwrap()
}

fn dfs(
    progs: &Vec<&str>,
    level: usize,
    z: i32,
    flag: &mut bool,
    range: &Vec<i32>,
    ans: &mut Vec<i32>,
) {
    let values = vec![14, 13, 15, 13, -2, 10, 13, -15, 11, -9, -9, -7, -4, -6];
    if level == 14 {
        if z == 0 {
            *flag = true;
        }
        return;
    }
    if [0, 1, 2, 3, 5, 6, 8].contains(&level) {
        // 1
        for &w in range.iter() {
            dfs(progs, level + 1, run(progs[level], z, w), flag, range, ans);
            if *flag {
                ans.push(w);
                return;
            }
        }
    } else {
        // 26
        let w = z % 26 + values[level];
        assert!(values[level] < 0);
        if !(w >= 1 && w <= 9) {
            return;
        }
        dfs(progs, level + 1, run(progs[level], z, w), flag, range, ans);
        if *flag {
            ans.push(w);
            return;
        }
    }
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let progs: Vec<_> = content.split("inp w\n").skip(1).collect();
    let to_ans = |ans: Vec<i32>| {
        ans.into_iter()
            .rev()
            .map(|x| char::from_digit(x as u32, 10).unwrap())
            .collect::<String>()
    };
    // 1
    let range1 = (1..=9).rev().collect();
    let mut ans1 = vec![];
    dfs(&progs, 0, 0, &mut false, &range1, &mut ans1);
    println!("{}", to_ans(ans1));

    // 2
    let range2 = (1..=9).collect();
    let mut ans2 = vec![];
    dfs(&progs, 0, 0, &mut false, &range2, &mut ans2);
    println!("{}", to_ans(ans2));
}
