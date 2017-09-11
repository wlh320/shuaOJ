/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.

*/

/* 思路: 递归遍历树的所有子树求和计数 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    map<int, int> cnt;
    
    int getSum(TreeNode* root) {
        if (!root) return 0;
        int sum = getSum(root->left) + getSum(root->right) + root->val;
        cnt[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        getSum(root);
        
        auto it = cnt.begin();
        int maxSum = it->second;
        
        for(; it != cnt.end(); ++it) {
            maxSum = max(maxSum, it->second);
        }
        for(it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second == maxSum) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
