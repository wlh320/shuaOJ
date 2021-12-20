use std::fs;

static mut VER_SUM: usize = 0;

fn parse_literal(bin: &str, mut cur: usize) -> (usize, u64) {
    let mut value = String::from("");
    loop {
        let v = &bin[cur..cur + 5];
        value.push_str(&v[1..]);
        if let Some('0') = v.chars().next() {
            break;
        }
        cur += 5;
    }
    cur = cur + 5;
    let v = u64::from_str_radix(&value, 2).unwrap();
    (cur, v)
}

fn parse_operator(bin: &str, t: &str, mut cur: usize) -> (usize, u64) {
    let length_id = &bin[cur..cur + 1];
    cur += 1;
    let (parse_len, vs) = match length_id {
        "0" => {
            let len = usize::from_str_radix(&bin[cur..cur + 15], 2).unwrap();
            cur += 15;
            parse(&bin[cur..cur + len], usize::MAX)
        }
        "1" => {
            let len = usize::from_str_radix(&bin[cur..cur + 11], 2).unwrap();
            cur += 11;
            parse(&bin[cur..], len)
        }
        _ => panic!("Invalid packet"),
    };
    (cur + parse_len, operate(t, vs))
}

fn operate(t: &str, vs: Vec<u64>) -> u64 {
    let type_id = usize::from_str_radix(t, 2).unwrap();
    match type_id {
        0 => vs.iter().sum(),
        1 => vs.iter().product(),
        2 => vs.into_iter().min().unwrap(),
        3 => vs.into_iter().max().unwrap(),
        5 if vs[0] > vs[1] => 1,
        6 if vs[0] < vs[1] => 1,
        7 if vs[0] == vs[1] => 1,
        _ => 0,
    }
}

fn parse(bin: &str, num_packet: usize) -> (usize, Vec<u64>) {
    let mut cur: usize = 0;
    let mut counter = 0;
    let mut vs = Vec::new();
    while cur < bin.len() && counter < num_packet {
        let (ver, type_id) = (&bin[cur..cur + 3], &bin[cur + 3..cur + 6]);
        unsafe {
            VER_SUM += usize::from_str_radix(ver, 2).unwrap();
        }
        let (next_cur, v) = match type_id {
            "100" => parse_literal(bin, cur + 6),
            t => parse_operator(bin, t, cur + 6),
        };
        vs.push(v);
        cur = next_cur;
        counter += 1;
    }
    (cur, vs)
}

fn main() {
    let content = fs::read_to_string("input").unwrap();
    let bin: String = content
        .trim()
        .chars()
        .map(|ch| format!("{:04b}", ch.to_digit(16).unwrap()))
        .collect();
    let bin = bin.trim_end_matches('0');
    let (_, vs) = parse(bin, usize::MAX);
    unsafe {
        println!("{}", VER_SUM);
    }
    println!("{}", vs[0]);
}
