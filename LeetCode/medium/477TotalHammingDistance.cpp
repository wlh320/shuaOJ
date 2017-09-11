/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.
*/

/* 思路: 不要单独考虑每个数,而是考虑每一个数位 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i = 0; i < 32; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                cnt += (nums[j] >> i) & 0x01;
            }
            total += cnt * (n-cnt);
        }
        return total;
    }
};
