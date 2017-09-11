/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/* 思路: 典型的回溯法 记录剩余的左右括号的数量
*/

class Solution {
public:
    vector<string> ans;
    void backtrace(int l, int r, string s) {
        if (l == 0 && r == 0) {
            ans.push_back(s);
            return ;
        }
        if (l > 0) {
            backtrace(l-1,r,s+"(");
        }
        if (r > l) {
            backtrace(l,r-1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrace(n, n, "");
        return ans;
    }
};
