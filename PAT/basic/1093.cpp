#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
char a[1000005];
char b[1000005];
int main()
{
    cin.getline(a, 1000005);
    cin.getline(b, 1000005);
    set<char> vis;
    for (int i = 0; a[i]; i++) {
        if (vis.find(a[i]) == vis.end()) {
            printf("%c", a[i]);
        }
        vis.insert(a[i]);
    }
    for (int i = 0; b[i]; i++) {
        if (vis.find(b[i]) == vis.end()) {
            printf("%c", b[i]);
        }
        vis.insert(b[i]);
    }
    printf("\n");
    return 0;
}