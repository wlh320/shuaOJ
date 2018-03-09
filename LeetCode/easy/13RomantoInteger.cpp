/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 *
 * 小数在大数前，要减去小数，其他没啥了
 */
class Solution {
public:
    int romanToInt(string s)
    {
        int sum = 0;
        map<char, int> m = { { 'I', 1 }, { 'X', 10 }, { 'C', 100 }, { 'M', 1000 }, { 'V', 5 }, { 'L', 50 }, { 'D', 500 } };
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (i + 1 < s.length() && m[s[i + 1]] > m[s[i]]) {
                sum += -m[ch];
            } else {
                sum += m[ch];
            }
        }
        return sum;
    }
};
