/* Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

统计个数之后搞一个最大堆
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> q;
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push(make_pair(it->second, it->first));
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            int res = q.top().second;
            ans.push_back(res);
            q.pop();
        }
        return ans;
    }
};
