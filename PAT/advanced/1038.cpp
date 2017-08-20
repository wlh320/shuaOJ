#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s[10000];
bool cmp(string a, string b) {
    return a + b < b + a;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s,s+n, cmp);
    string res;
    for(int i = 0; i < n; ++i) {
        res += s[i];
    }
    int i;
    int len = res.length();
    for(i = 0; res[i]; ++i) {
        if (res[i] != '0') {
            break;
        }
    }
    if (i == len) {
        cout << 0 << endl;
    } else {
        cout << res.substr(i, len-i) << endl;
    }
    return 0;
}
