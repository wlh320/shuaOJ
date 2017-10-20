/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

/* 用位运算标记单词的每一个字符, 相与为0则不重复 */

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bit(words.size(), 0);
        for(int i = 0; i < words.size(); ++i) {
            string tmp = words[i];
            for(int j = 0; j < tmp.size(); ++j) {
                bit[i] |= (1 << (tmp[j]-'a'));
            }
        }
        int maxp = 0;
        for(int i = 0; i < bit.size(); ++i) {
            for(int j = i+1; j < bit.size(); ++j) {
                if ((bit[i] & bit[j]) == 0) {
                    int p = words[i].size() * words[j].size();
                    maxp = max(p, maxp);
                }
            }
        }
        return maxp;
    }
};
