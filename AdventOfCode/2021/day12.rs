use std::collections::{HashMap, HashSet};
use std::fs;

fn is_lowercase(s: &str) -> bool {
    s.chars().all(|ch| ch.is_lowercase())
}

fn dfs1<'a>(
    map: &HashMap<&str, HashSet<&'a str>>,
    v: &str,
    vis: &mut HashMap<&'a str, i32>,
    count: &mut i32,
) {
    if v == "end" {
        *count += 1;
        return;
    }
    for node in map[v].iter() {
        if *vis.entry(node).or_insert(0) < 1 {
            if is_lowercase(node) {
                *vis.get_mut(node).unwrap() += 1;
            }
            dfs1(map, node, vis, count);
            if is_lowercase(node) {
                *vis.get_mut(node).unwrap() -= 1;
            }
        }
    }
}

fn dfs2<'a>(
    map: &HashMap<&str, HashSet<&'a str>>,
    v: &str,
    vis: &mut HashMap<&'a str, i32>,
    count: &mut i32,
    flag: &mut bool,
) {
    if v == "end" {
        *count += 1;
        return;
    }
    for node in map[v].iter() {
        // flag controls if we can visit some node twice
        let limit = if *flag { 1 } else { 2 };
        if *vis.entry(node).or_insert(0) < limit {
            if is_lowercase(node) {
                *vis.get_mut(node).unwrap() += 1;
                if vis[node] == 2 {
                    *flag = true;
                }
            }
            dfs2(map, node, vis, count, flag);
            if is_lowercase(node) {
                if vis[node] == 2 {
                    *flag = false;
                }
                *vis.get_mut(node).unwrap() -= 1;
            }
        }
    }
}

fn main() {
    let content = fs::read_to_string("input").unwrap();
    let mut map = HashMap::<&str, HashSet<&str>>::new();
    for line in content.lines() {
        let (s, t) = line.trim().split_once('-').unwrap();
        map.entry(s).or_default().insert(t);
        map.entry(t).or_default().insert(s);
    }
    // 1
    let mut ans = 0;
    let mut vis = HashMap::<&str, i32>::new();
    *vis.entry("start").or_insert(0) += 1;
    dfs1(&map, "start", &mut vis, &mut ans);
    println!("{}", ans);
    // 2
    let mut ans = 0;
    let mut vis = HashMap::<&str, i32>::new();
    let mut flag = false;
    *vis.entry("start").or_insert(0) = 2;
    dfs2(&map, "start", &mut vis, &mut ans, &mut flag);
    println!("{}", ans);
}
