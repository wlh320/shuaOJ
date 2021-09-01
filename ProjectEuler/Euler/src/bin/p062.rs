use euler::to_digit_counter;
use std::collections::HashMap;

fn main() {
	let mut map = HashMap::new();
	for n in 1u64.. {
		let cube = n.pow(3);
		let entry = map.entry(to_digit_counter(cube)).or_insert(Vec::<u64>::new());
		entry.push(cube);
		if entry.len() == 5 {
			println!("{}", entry.iter().min().unwrap());
			break;
		}
	}
}
