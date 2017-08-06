#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string pwd; // fuck fgets!
    int n;
    cin >> pwd >> n;
    getchar();
    while(true) {
        string tryPwd;
        getline(cin, tryPwd);
        if (tryPwd == "#") {
            break;
        }
        if (pwd == tryPwd) {
            printf("Welcome in\n");
            break;
        } else {
            printf("Wrong password: %s\n", tryPwd.c_str());
            n--;
        }
        if (n == 0) {
            printf("Account locked\n");
            break;
        }
    }
    return 0;
}
