use std::collections::HashMap;
use std::fs;
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let score_map = HashMap::from([
        (')', 3),
        (']', 57),
        ('}', 1197),
        ('>', 25137),
        ('(', 1),
        ('[', 2),
        ('{', 3),
        ('<', 4),
    ]);
    let pair = HashMap::from([(')', '('), ('}', '{'), (']', '['), ('>', '<')]);
    let mut ans = 0;
    for line in content.lines() {
        let mut stack = vec![];
        for ch in line.chars() {
            match ch {
                '(' | '[' | '{' | '<' => stack.push(ch),
                ')' | ']' | '}' | '>' => {
                    if stack.last().unwrap_or(&' ') == pair.get(&ch).unwrap() {
                        stack.pop();
                    } else {
                        ans += score_map[&ch];
                        break;
                    }
                }
                _ => (),
            };
        }
    }
    println!("{}", ans);

    // 2
    let mut scores = vec![];
    for line in content.lines() {
        let mut stack = vec![];
        let mut score: u64 = 0;
        let mut corrupt = false;
        for ch in line.chars() {
            match ch {
                '(' | '[' | '{' | '<' => stack.push(ch),
                ')' | ']' | '}' | '>' => {
                    if stack.last().unwrap_or(&' ') == pair.get(&ch).unwrap() {
                        stack.pop();
                    } else {
                        ans += score_map[&ch];
                        corrupt = true;
                        break;
                    }
                }
                _ => (),
            };
        }
        if corrupt {
            continue;
        }
        while !stack.is_empty() {
            let ch = stack.pop().unwrap();
            score *= 5;
            match ch {
                '(' | '[' | '{' | '<' => score += score_map[&ch],
                _ => (),
            };
        }
        scores.push(score);
    }
    scores.sort();
    println!("{}", scores[scores.len() / 2]);
}
