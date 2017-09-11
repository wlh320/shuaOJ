/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

/* 判断两个字符串是否具有相同的结构
   两个数组分别记录该字符上次出现的位置,如果不同就false
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_pos[128];
        int t_pos[128];
        for(int i = 0; i < 128; ++i) s_pos[i] = t_pos[i] = -1;
        int len = s.size();
        char cs, ct;
        for(int i = 0; i < len; ++i) {
            cs = s[i]; ct = t[i];
            if (s_pos[cs] != t_pos[ct]) return false;
            s_pos[cs] = t_pos[ct] = i;
        }
        return true;
    }
};
