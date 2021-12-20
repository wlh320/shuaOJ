use std::collections::HashSet;

fn shoot(mut vx: i32, mut vy: i32) -> Option<i32> {
    let (x0, x1) = (102, 157);
    let (y0, y1) = (-146, -90);
    let mut traj = HashSet::<(i32, i32)>::new();
    let (mut x, mut y) = (0, 0);
    for _ in 0.. {
        x += vx;
        y += vy;
        traj.insert((x, y));
        vx -= vx.signum();
        vy -= 1;
        if x >= x0 && x <= x1 && y >= y0 && y <= y1 {
            return Some(traj.iter().map(|t| t.1).max().unwrap());
        }
        if (x > x1 && vx >= 0) || (y < y0 && vy <= 0) || (x < x0 && vx <= 0) {
            return None;
        }
    }
    None
}
fn main() {
    // 1
    let ans: i32 = (0..158)
        .flat_map(|x| {
            (-147..200)
                .map(|y| shoot(x, y).unwrap_or_else(|| i32::MIN))
                .collect::<Vec<i32>>()
        })
        .max()
        .unwrap();
    println!("{}", ans);

    // 2
    let ans = (0..158)
        .map(|x| (-147..200).filter(move |&y| shoot(x, y).is_some()).count())
        .sum::<usize>();
    println!("{}", ans);
}
