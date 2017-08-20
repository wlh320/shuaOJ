#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> cnt;
bool isalnum(char ch)
{
    return (ch >= 'a' && ch <= 'z' )||
           (ch >= '0' && ch <= '9');
}
int main()
{
    string str;
    getline(cin, str);
    int begin = 0;
    for(int i = 0; str[i]; ++i) { // lower
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a'-'A';
        }
    }
    for(int i = 1; str[i-1]; ++i) {
        if (isalnum(str[i]) && !isalnum(str[i-1])) {
            begin = i;
        }
        if (!isalnum(str[i]) && isalnum(str[i-1])) {
            cnt[str.substr(begin, i-begin)]++;
        }
    }
    map<string, int>::iterator it;
    string maxstr;
    int max = 0;
    for(it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second > max) {
            maxstr = it->first;
            max = it->second;
        }
    } 
    cout << maxstr << ' ' << max << endl;
    return 0;
}
