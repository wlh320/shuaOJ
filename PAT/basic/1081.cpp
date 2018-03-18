#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string check(string password)
{
    if (password.length() < 6) {
        return "is tai duan le.";
    }
    bool digit = false;
    bool alpha = false;
    for (unsigned int i = 0; i < password.length(); i++) {
        if (isalpha(password[i])) {
            alpha = true;
        } else if (isdigit(password[i])) {
            digit = true;
        } else if (password[i] != '.') {
            return "is tai luan le.";
        }
    }
    if (digit && !alpha) {
        return "needs zi mu.";
    } else if (!digit && alpha) {
        return "needs shu zi.";
    }
    return "is wan mei.";
}
int main()
{
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string password;
        getline(cin, password, '\n');
        string result = check(password);
        cout << "Your password " << result << endl;
    }
    return 0;
}
