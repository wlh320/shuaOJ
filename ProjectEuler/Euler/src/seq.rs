// Fibonacci
use std::ops::Add;
pub struct Fib<T>(pub T, pub T);

impl<T> Iterator for Fib<T>
where
    T: Add<Output = T> + Clone,
{
    type Item = T;
    fn next(&mut self) -> Option<T> {
        let next: T = self.0.clone() + self.1.clone();
        self.0 = self.1.clone();
        self.1 = next;
        Some(self.0.clone())
    }
}

// Collatz
pub struct Collatz(pub u32);

impl Iterator for Collatz {
    type Item = u32;
    fn next(&mut self) -> Option<u32> {
        let ret = if self.0 == 0 { None } else { Some(self.0) };
        self.0 = match self.0 {
            1 => 0,
            x if x % 2 == 0 => self.0 / 2,
            _ => 3 * self.0 + 1,
        };
        ret
    }
}
