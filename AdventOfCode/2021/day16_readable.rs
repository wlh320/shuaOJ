use std::fs;

fn read(input: &mut impl Iterator<Item = char>, len: usize) -> String {
    (0..len).map_while(|_| input.next()).collect::<String>()
}
fn operate(type_id: u8, vs: Vec<u64>) -> u64 {
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

#[derive(Debug)]
enum Payload {
    Literal { val: u64 },
    Operator { sub: Vec<Packet> },
}
#[derive(Debug)]
struct Packet {
    ver: u8,
    type_id: u8,
    payload: Payload,
}
impl Packet {
    fn parse_literal(input: &mut impl Iterator<Item = char>) -> Payload {
        let mut vstr = String::from("");
        loop {
            let word = read(input, 5);
            vstr.push_str(&word[1..]);
            if word.starts_with('0') {
                break;
            }
        }
        Payload::Literal {
            val: u64::from_str_radix(&vstr, 2).unwrap(),
        }
    }
    fn parse_operator(input: &mut impl Iterator<Item = char>) -> Payload {
        let l_str = read(input, 1);
        let length_id = u8::from_str_radix(&l_str, 2).unwrap();
        let mut sub_packets = Vec::new();
        match length_id {
            0 => {
                let len = u16::from_str_radix(&read(input, 15), 2).unwrap();
                let subinput = read(input, len as usize);
                let mut subinput = subinput.chars().peekable();
                while subinput.peek().is_some() {
                    let packet = Packet::parse(&mut subinput);
                    sub_packets.push(packet);
                }
            }
            1 => {
                let num = u16::from_str_radix(&read(input, 11), 2).unwrap();
                for _ in 0..num {
                    let packet = Packet::parse(input);
                    sub_packets.push(packet);
                }
            }
            _ => (),
        };
        Payload::Operator { sub: sub_packets }
    }
    fn parse(input: &mut impl Iterator<Item = char>) -> Packet {
        let ver = u8::from_str_radix(&read(input, 3), 2).unwrap();
        let type_id = u8::from_str_radix(&read(input, 3), 2).unwrap();
        let payload = match type_id {
            4 => Self::parse_literal(input),
            _ => Self::parse_operator(input),
        };
        Packet {
            ver,
            type_id,
            payload,
        }
    }
    fn ver_sum(&self) -> u64 {
        self.ver as u64
            + match &self.payload {
                Payload::Literal { val: _ } => 0,
                Payload::Operator { sub } => sub.iter().map(|p| p.ver_sum()).sum::<u64>(),
            }
    }
    fn eval(&self) -> u64 {
        match &self.payload {
            Payload::Literal { val } => *val,
            Payload::Operator { sub } => {
                operate(self.type_id, sub.iter().map(|p| p.eval()).collect())
            }
        }
    }
}

fn main() {
    let content = fs::read_to_string("input").unwrap();
    let input: String = content
        .chars()
        .map(|ch| format!("{:04b}", ch.to_digit(16).unwrap()))
        .collect();
    let packet = Packet::parse(&mut input.chars());
    // 1
    println!("{}", packet.ver_sum());
    // 2
    println!("{}", packet.eval());
}
