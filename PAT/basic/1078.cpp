#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
string encrypt(const string& plain)
{
    int len = plain.size();
    unsigned int cnt = 1;
    string res;
    // include '\0' to end last count
    for (int i = 1; i < len + 1; ++i) {
        if (plain[i] != plain[i - 1]) {
            if (cnt > 1) {
                res.append(to_string(cnt));
            }
            res.append(1, plain[i - 1]);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    return res;
}

string decrypt(const string& cipher)
{
    int len = cipher.size();
    string res;
    unsigned int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (cipher[i] >= '0' && cipher[i] <= '9') {
            cnt *= 10;
            cnt += (cipher[i] - '0');
        } else {
            cnt = (cnt == 0 ? 1 : cnt);
            res.append(cnt, cipher[i]);
            cnt = 0;
        }
    }
    return res;
}

int main()
{
    char type = getchar();
    getchar();
    string plain;
    string cipher;
    if (type == 'C') {
        getline(cin, plain, '\n');
        cout << encrypt(plain);
    } else if (type == 'D') {
        getline(cin, cipher, '\n');
        cout << decrypt(cipher);
    }
    return 0;
}
