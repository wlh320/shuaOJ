use std::cmp::{max, min};
use std::collections::HashMap;
use std::fs;

type Range = Vec<(isize, isize)>;

fn part1(vins: &Vec<(bool, Vec<(isize, isize)>)>) -> usize {
    let mut status: HashMap<(isize, isize, isize), bool> = HashMap::new();
    for (onoff, ranges) in vins.iter() {
        let (xlo, xhi) = ranges[0];
        let (ylo, yhi) = ranges[1];
        let (zlo, zhi) = ranges[2];

        let xlo = if xlo <= -50 { -50 } else { xlo };
        let xhi = if xlo >= 50 { 50 } else { xhi };
        let ylo = if ylo <= -50 { -50 } else { ylo };
        let yhi = if ylo >= 50 { 50 } else { yhi };
        let zlo = if zlo <= -50 { -50 } else { zlo };
        let zhi = if zlo >= 50 { 50 } else { zhi };

        for x in xlo..=xhi {
            for y in ylo..=yhi {
                for z in zlo..=zhi {
                    *status.entry((x, y, z)).or_insert(false) = *onoff;
                }
            }
        }
    }
    let count = status.iter().filter(|(_, stat)| **stat).count();
    return count;
}

fn intersection(a: &Range, b: &Range) -> Option<Range> {
    let mut c: Range = Range::new();
    for i in 0..3 {
        if a[i].0 > b[i].1 || a[i].1 < b[i].0 {
            return None;
        }
        c.push((max(a[i].0, b[i].0), min(a[i].1, b[i].1)));
    }
    Some(c)
}

fn part2(vins: &Vec<(bool, Range)>) -> usize {
    let mut on_ranges: HashMap<Range, isize> = HashMap::new();
    for (onoff, range) in vins.iter() {
        let mut new_on_ranges = on_ranges.clone();
        for (on_range, weight) in on_ranges.iter() {
            if let Some(is) = intersection(on_range, range) {
                *new_on_ranges.entry(is).or_insert(0) -= weight;
            }
        }
        if *onoff {
            *new_on_ranges.entry(range.clone()).or_insert(0) += 1;
        }
        on_ranges = new_on_ranges;
    }
    on_ranges
        .into_iter()
        .map(|(range, weight)| range.iter().map(|t| t.1 - t.0 + 1).product::<isize>() * weight)
        .sum::<isize>() as usize
}
fn main() {
    let content = fs::read_to_string("input").unwrap();
    let mut vins: Vec<(bool, Range)> = vec![];
    for line in content.lines() {
        let (onoff, range) = line.split_once(' ').unwrap();
        let ranges: Vec<(isize, isize)> = range
            .split(',')
            .map(|s| {
                let (lo, hi) = &s[2..].split_once("..").unwrap();
                (lo.parse::<isize>().unwrap(), hi.parse::<isize>().unwrap())
            })
            .collect();
        let onoff: bool = if onoff == "on" { true } else { false };
        vins.push((onoff, ranges));
    }
    // 1
    let count = part1(&vins);
    println!("{}", count);
    // 2
    let count = part2(&vins);
    println!("{}", count);
}
