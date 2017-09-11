/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* 思路: 二叉树层次遍历 用队列实现 这里是每一层都要存一个vector 需要一次处理一层*/
 class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if(root) q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            while(sz--) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
                tmp.push_back(p->val);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
