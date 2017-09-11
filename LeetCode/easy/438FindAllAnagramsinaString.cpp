/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

/* 滑动窗口 窗口大小 len(p) 每次比较统计值 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenp = p.size();
        int lens = s.size();
        vector<int> s_cnt(26, 0), p_cnt(26, 0);
        vector<int> ans;
        for(int i = 0; i < lenp; ++i) {
            p_cnt[p[i]-'a']++;
            s_cnt[s[i]-'a']++;
        }
        if (p_cnt == s_cnt) ans.push_back(0);
        for(int i = lenp; i < lens; ++i) {
            s_cnt[s[i]-'a']++;
            s_cnt[s[i-lenp]-'a']--;
            if (p_cnt == s_cnt) {
                ans.push_back(i+1-lenp);
            }
        }
        return ans;
    }
};
