use std::cmp::{max, min};
use std::collections::{HashMap, HashSet};
fn get_fee(ch: i32) -> i32 {
    match ch {
        1 => 1,
        2 => 10,
        3 => 100,
        4 => 1000,
        _ => 0,
    }
}

fn is_win(room1: &mut Vec<i32>, room2: &mut Vec<i32>) -> bool {
    for i in 0..4 {
        if room1[i] != i as i32 + 1 || room2[i] != i as i32 + 1 {
            return false;
        }
    }
    true
}

fn can1_move(hall: &Vec<i32>, start: usize, target: usize) -> bool {
    let idxmap = vec![2i32, 4, 6, 8];
    if hall[target] != 0 {
        return false;
    }
    let start = idxmap[start] as usize;
    for i in min(start, target)..max(start, target) {
        if hall[i] != 0 {
            return false;
        }
    }
    true
}
fn can2_move(room1: &Vec<i32>, hall: &Vec<i32>, start: usize, target: usize) -> bool {
    hall[target] == 0 && room1[start] == 0 && can1_move(hall, start, target)
}

fn can_move_hall(hall: &Vec<i32>, start: usize, target: usize) -> bool {
    let (start, target) = (min(start, target), max(start, target));
    for i in start + 1..target {
        if hall[i] != 0 {
            return false;
        }
    }
    true
}

fn get_state(hall: &mut Vec<i32>, room1: &mut Vec<i32>, room2: &mut Vec<i32>) -> String {
    let h = hall
        .iter()
        .map(|x| char::from_u32(*x as u32).unwrap())
        .collect::<String>();
    let r1 = room1
        .iter()
        .map(|x| char::from_u32(*x as u32).unwrap())
        .collect::<String>();
    let r2 = room2
        .iter()
        .map(|x| char::from_u32(*x as u32).unwrap())
        .collect::<String>();
    h + &r1 + &r2
}

fn dfs(
    hall: &mut Vec<i32>,
    room1: &mut Vec<i32>,
    room2: &mut Vec<i32>,
    energy: i32,
    step: i32,
    results: &mut HashSet<i32>,
    freeze1: &mut Vec<bool>,
    freeze2: &mut Vec<bool>,
    seen: &mut HashMap<String, i32>,
) {
    if results.len() > 0 && energy > *results.iter().min().unwrap() {
        return;
    }
    let state = get_state(hall, room1, room2);
    if seen.contains_key(&state) {
        if energy > *seen.get(&state).unwrap() {
            return;
        } else {
            *seen.get_mut(&state).unwrap() = energy;
        }
    } else {
        *seen.entry(state).or_insert(0) += energy;
    }

    let idxmap = vec![2i32, 4, 6, 8];
    if is_win(room1, room2) {
        results.insert(energy);
    } else {
        // room1 -> hall
        for i in 0..4 {
            if room1[i] == 0 || freeze1[i] {
                continue;
            }
            for target in [0, 1, 3, 5, 7, 9, 10] {
                if can1_move(hall, i, target) {
                    let fee = get_fee(room1[i]) * ((target as i32 - idxmap[i]).abs() + 1);
                    let tmp = room1[i];
                    room1[i] = 0;
                    hall[target] = tmp;
                    dfs(
                        hall,
                        room1,
                        room2,
                        energy + fee,
                        step + 1,
                        results,
                        freeze1,
                        freeze2,
                        seen,
                    );
                    room1[i] = tmp;
                    hall[target] = 0;
                }
            }
        }
        // room2 -> hall
        for i in 0..4 {
            if room2[i] == 0 || freeze2[i] {
                continue;
            }
            for target in [0, 1, 3, 5, 7, 9, 10] {
                if can2_move(room1, hall, i, target) {
                    let fee = get_fee(room2[i]) * ((target as i32 - idxmap[i]).abs() + 2);
                    let tmp = room2[i];
                    room2[i] = 0;
                    hall[target] = tmp;
                    dfs(
                        hall,
                        room1,
                        room2,
                        energy + fee,
                        step + 1,
                        results,
                        freeze1,
                        freeze2,
                        seen,
                    );
                    room2[i] = tmp;
                    hall[target] = 0;
                }
            }
        }
        // return room
        for i in [0, 1, 3, 5, 7, 9, 10] {
            if hall[i] != 0 {
                let xia = hall[i];
                let target = idxmap[(xia - 1) as usize] as usize;
                // to room2
                if room1[(xia - 1) as usize] == 0
                    && room2[(xia - 1) as usize] == 0
                    && can_move_hall(hall, i, target)
                {
                    let fee = get_fee(xia) * ((target as i32 - i as i32).abs() + 2);
                    hall[i] = 0;
                    room2[(xia - 1) as usize] = xia;
                    freeze2[(xia - 1) as usize] = true;
                    dfs(
                        hall,
                        room1,
                        room2,
                        energy + fee,
                        step + 1,
                        results,
                        freeze1,
                        freeze2,
                        seen,
                    );
                    freeze2[(xia - 1) as usize] = false;
                    room2[(xia - 1) as usize] = 0;
                    hall[i] = xia;
                }
                // to room1
                if room1[(xia - 1) as usize] == 0
                    && room2[(xia - 1) as usize] == xia
                    && can_move_hall(hall, i, target)
                {
                    let fee = get_fee(xia) * ((target as i32 - i as i32).abs() + 1);
                    hall[i] = 0;
                    room1[(xia - 1) as usize] = xia;
                    freeze1[(xia - 1) as usize] = true;
                    dfs(
                        hall,
                        room1,
                        room2,
                        energy + fee,
                        step + 1,
                        results,
                        freeze1,
                        freeze2,
                        seen,
                    );
                    freeze1[(xia - 1) as usize] = false;
                    room1[(xia - 1) as usize] = 0;
                    hall[i] = xia;
                }
            }
        }
    }
}

fn main() {
    let mut hall = vec![0; 11];
    let mut room1 = vec![4, 3, 1, 2];
    let mut room2 = vec![2, 3, 4, 1];
    // let mut room1 = vec![2, 3, 2, 4];
    // let mut room2 = vec![1, 4, 3, 1];
    let mut results = HashSet::new();
    let mut freeze1 = vec![false, false, false, false];
    let mut freeze2 = vec![room2[0] == 1, room2[1] == 2, room2[2] == 3, room2[3] == 4];
    let mut seen: HashMap<String, i32> = HashMap::new();
    dfs(
        &mut hall,
        &mut room1,
        &mut room2,
        0,
        0,
        &mut results,
        &mut freeze1,
        &mut freeze2,
        &mut seen,
    );
    println!("{}", results.iter().min().unwrap());
}
