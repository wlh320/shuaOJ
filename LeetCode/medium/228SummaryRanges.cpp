/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
*/
/* 没什么技术含量 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        int begin = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i]-nums[i-1] != 1) {
                if (i == begin + 1) {
                    ans.push_back(to_string(nums[begin]));
                } else {
                    string tmp = to_string(nums[begin]);
                    tmp += "->";
                    tmp += to_string(nums[i-1]);
                    ans.push_back(tmp);
                }
                begin = i;
            }
        }
        return ans;
    }
};
