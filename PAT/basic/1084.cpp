// 题目描述有毒，d=1的时候还是合并到一起计算的啊啊啊啊啊啊啊啊
#include <iostream>
#include <string>
using namespace std;
string next_string(string s)
{
    int cnt = 1;
    string result;
    for (unsigned int i = 1; i <= s.length(); i++) {
        if (s[i] != s[i - 1] || s[i] == '\0') {
            result += string(1, s[i - 1]);
            result += string(1, '0' + cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    return result;
}
int main()
{
    int d, n;
    cin >> d >> n;
    string result(1, '0' + d);
    for (int i = 1; i < n; i++) {
        result = next_string(result);
    }
    cout << result << endl;
    return 0;
}
