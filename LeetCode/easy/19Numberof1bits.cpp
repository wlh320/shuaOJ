/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

class Solution {
public:
    // naive!!!
    // int hammingWeight(uint32_t n) {
    //     int sum = 0;
    //     for(int i = 0; i < 32; ++i) {
    //         sum += (n & 0x01);
    //         n >>= 1;
    //     }
    //     return sum;
    // }
    

    // trick: n & (n-1)
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n) {
            n &= (n-1);
            sum++;
        }
        return sum;
    }
};

// O(1) solutions from Discuss column 
// AMAZING!

// This is a naive implementation, shown for comparison, and to help in understanding the better functions. 
// It uses 24 arithmetic operations (shift, add, and).
int hammingWeight(uint32_t n)
{
    n = (n & 0x55555555) + (n >>  1 & 0x55555555); // put count of each  2 bits into those  2 bits 
    n = (n & 0x33333333) + (n >>  2 & 0x33333333); // put count of each  4 bits into those  4 bits 
    n = (n & 0x0F0F0F0F) + (n >>  4 & 0x0F0F0F0F); // put count of each  8 bits into those  8 bits 
    n = (n & 0x00FF00FF) + (n >>  8 & 0x00FF00FF); // put count of each 16 bits into those 16 bits 
    n = (n & 0x0000FFFF) + (n >> 16 & 0x0000FFFF); // put count of each 32 bits into those 32 bits 
    return n;
}

// This uses fewer arithmetic operations than any other known implementation on machines with slow multiplication.
// It uses 17 arithmetic operations.
int hammingWeight(uint32_t n)
{
    n -= (n >> 1) & 0x55555555; //put count of each 2 bits into those 2 bits
    n = (n & 0x33333333) + (n >> 2 & 0x33333333); //put count of each 4 bits into those 4 bits
    n = (n + (n >> 4)) & 0x0F0F0F0F; //put count of each 8 bits into those 8 bits
    n += n >> 8; // put count of each 16 bits into those 8 bits
    n += n >> 16; // put count of each 32 bits into those 8 bits
    return n & 0xFF;
}

// This uses fewer arithmetic operations than any other known implementation on machines with fast multiplication.
// It uses 12 arithmetic operations, one of which is a multiply.
int hammingWeight(uint32_t n)
{
    n -= (n >> 1) & 0x55555555; // put count of each 2 bits into those 2 bits
    n = (n & 0x33333333) + (n >> 2 & 0x33333333); // put count of each 4 bits into those 4 bits
    n = (n + (n >> 4)) & 0x0F0F0F0F; // put count of each 8 bits into those 8 bits 
    return n * 0x01010101 >> 24; // returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24)
}
