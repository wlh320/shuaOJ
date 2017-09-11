/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

/* 二分搜索的变种 不是找相等的位置, 而是找target应该在的位置*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = (l+r)/2;
            if (nums[mid] >= target) r = mid;
            else if (nums[mid] < target) l = mid+1;
        }
        return r;
    }
};
