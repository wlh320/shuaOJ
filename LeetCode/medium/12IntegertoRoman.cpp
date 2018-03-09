/*Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

贪心从大往小找
*/
class Solution {
public:
    string intToRoman(int num)
    {
        string digits[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I", "" };
        int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 0 };
        string roman;
        while (num) {
            int i;
            for (i = 0; num < values[i]; i++)
                ;
            num -= values[i];
            roman += digits[i];
        }
        return roman;
    }
};
