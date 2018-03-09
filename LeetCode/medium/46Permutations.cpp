/* Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:
    void per(vector<int>& nums, int low, int high, vector<vector<int>>& ans)
    {
        if (low == high) {
            ans.push_back(nums);
        }
        for (int i = low; i < high; ++i) {
            swap(nums[i], nums[low]);
            per(nums, low + 1, high, ans);
            swap(nums[i], nums[low]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        per(nums, 0, nums.size(), ans);
        return ans;
    }
};
