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

fn to_real_idx(id: usize) -> usize {
    2 * (id + 1)
}

fn is_win(rooms: &Vec<Vec<i32>>) -> bool {
    for room in rooms.iter() {
        for i in 0..4 {
            if room[i] != i as i32 + 1 {
                return false;
            }
        }
    }
    true
}

// fn print_room(
//     step: i32,
//     energy: i32,
//     hall: &mut Vec<i32>,
//     rooms: &mut Vec<Vec<i32>>,
//     results: &HashSet<i32>,
// ) {
//     println!("Step {}", step);
//     println!("Energy {}", energy);
//     println!("Result {:?}", results);
//     for i in 0..hall.len() {
//         print!("{}", hall[i]);
//     }
//     println!();
//     for room in rooms.iter() {
//         for i in 0..hall.len() {
//             if i == 2 || i == 4 || i == 6 || i == 8 {
//                 print!("{}", room[i / 2 - 1]);
//             } else {
//                 print!("{}", "#");
//             }
//         }
//         println!();
//     }
//     println!();
// }

fn get_state(hall: &Vec<i32>, rooms: &Vec<Vec<i32>>) -> String {
    let h = hall
        .iter()
        .map(|x| char::from_u32(*x as u32).unwrap())
        .collect::<String>();
    let mut ans = h;
    for room in rooms.iter() {
        let r = room
            .iter()
            .map(|x| char::from_u32(*x as u32).unwrap())
            .collect::<String>();
        ans += &r;
    }
    ans
}

fn can_move_to_hall(
    hall: &Vec<i32>,
    rooms: &Vec<Vec<i32>>,
    rid: usize,
    src: usize,
    dst: usize,
) -> bool {
    if rooms[rid][src] == 0 {
        return false;
    }
    for i in 0..rid {
        if rooms[i][src] != 0 {
            return false;
        }
    }
    let src = to_real_idx(src);
    let (src, dst) = (min(src, dst), max(src, dst));
    for i in src..=dst {
        if hall[i] != 0 {
            return false;
        }
    }
    true
}

fn can_move_to_room(
    hall: &Vec<i32>,
    rooms: &Vec<Vec<i32>>,
    rid: usize,
    dst: usize,
    src: usize, // hall idx
) -> bool {
    if hall[src] == 0 {
        return false;
    }
    let xia = hall[src];
    for i in 0..=rid {
        if rooms[i][dst] != 0 {
            return false;
        }
    }
    for i in rid + 1..rooms.len() {
        if rooms[i][dst] != xia {
            return false;
        }
    }
    let dst = to_real_idx(dst);
    let (src, dst) = (min(src, dst), max(src, dst));
    for i in src + 1..dst {
        if hall[i] != 0 {
            return false;
        }
    }
    true
}

fn dfs(
    hall: &mut Vec<i32>,
    rooms: &mut Vec<Vec<i32>>,
    freeze: &mut Vec<Vec<bool>>,
    energy: i32,
    step: i32,
    results: &mut HashSet<i32>,
    seen: &mut HashMap<String, i32>,
) {
    if results.len() > 0 && energy > *results.iter().min().unwrap() {
        return;
    }
    let state = get_state(hall, rooms);
    match seen.get(&state) {
        None => *seen.entry(state).or_insert(0) = energy,
        Some(e) if energy <= *e => *seen.get_mut(&state).unwrap() = energy,
        _ => return,
    };
    if is_win(rooms) {
        results.insert(energy);
        return;
    }
    // print_room(step, energy, hall, rooms, results);

    // room -> hall
    for i in 0..rooms.len() {
        for j in 0..4 {
            for dst in [0, 1, 3, 5, 7, 9, 10] {
                if can_move_to_hall(hall, rooms, i, j, dst) && !freeze[i][j] {
                    let xia = rooms[i][j];
                    rooms[i][j] = 0;
                    hall[dst] = xia;
                    let fee =
                        ((to_real_idx(j) as i32 - dst as i32).abs() + 1 + i as i32) * get_fee(xia);
                    dfs(hall, rooms, freeze, energy + fee, step + 1, results, seen);
                    hall[dst] = 0;
                    rooms[i][j] = xia;
                }
            }
        }
    }
    // hall -> room
    for src in [0, 1, 3, 5, 7, 9, 10] {
        for i in 0..rooms.len() {
            let xia = hall[src];
            if xia == 0 {
                continue;
            }
            let dst = xia as usize - 1;
            if can_move_to_room(hall, rooms, i, dst, src) {
                hall[src] = 0;
                rooms[i][dst] = xia;
                freeze[i][dst] = true;
                let fee =
                    ((to_real_idx(dst) as i32 - src as i32).abs() + 1 + i as i32) * get_fee(xia);
                dfs(hall, rooms, freeze, energy + fee, step + 1, results, seen);
                freeze[i][dst] = false;
                rooms[i][dst] = 0;
                hall[src] = xia;
            }
        }
    }
}

fn get_freeze(rooms: &Vec<Vec<i32>>) -> Vec<Vec<bool>> {
    let mut freeze = vec![vec![false; 4]; rooms.len()];
    for i in (0..rooms.len()).rev() {
        for j in 0..4 {
            if rooms[i][j] == (j + 1) as i32 {
                if i == rooms.len() - 1 || freeze[i + 1][j] {
                    freeze[i][j] = true;
                }
            }
        }
    }
    freeze
}

fn get_part1_input() -> Vec<Vec<i32>> {
    let mut rooms: Vec<Vec<i32>> = vec![];
    // rooms.push(vec![2, 3, 2, 4]);
    // rooms.push(vec![1, 4, 3, 1]);
    rooms.push(vec![4, 3, 1, 2]);
    rooms.push(vec![2, 3, 4, 1]);
    rooms
}

fn get_part2_input() -> Vec<Vec<i32>> {
    let mut rooms: Vec<Vec<i32>> = vec![];
    // rooms.push(vec![2, 3, 2, 4]);
    rooms.push(vec![4, 3, 1, 2]);

    rooms.push(vec![4, 3, 2, 1]);
    rooms.push(vec![4, 2, 1, 3]);

    // rooms.push(vec![1, 4, 3, 1]);
    rooms.push(vec![2, 3, 4, 1]);
    rooms
}

fn main() {
    // 1
    let mut hall = vec![0; 11];
    let mut rooms = get_part1_input();
    let mut freeze = get_freeze(&rooms);
    let mut results = HashSet::new();
    let mut seen: HashMap<String, i32> = HashMap::new();
    dfs(
        &mut hall,
        &mut rooms,
        &mut freeze,
        0,
        0,
        &mut results,
        &mut seen,
    );
    println!("{}", results.iter().min().unwrap());

    // 2
    let mut hall = vec![0; 11];
    let mut rooms = get_part2_input();
    let mut freeze = get_freeze(&rooms);
    let mut results = HashSet::new();
    let mut seen: HashMap<String, i32> = HashMap::new();
    dfs(
        &mut hall,
        &mut rooms,
        &mut freeze,
        0,
        0,
        &mut results,
        &mut seen,
    );
    println!("{}", results.iter().min().unwrap());
}
