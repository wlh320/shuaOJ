#include <cstdio>
#include <iostream>
using namespace std;
#define MAXLEN 100001
char s1[MAXLEN];
char s2[MAXLEN];
bool map[256];
int main()
{
    cin.getline(s1, MAXLEN-1);
    cin.getline(s2, MAXLEN-1);
    for(int i = 0; s2[i]; ++i) {
        map[s2[i]] = true;
    }
    for(int i = 0; s1[i]; ++i) {
        if (!map[s1[i]]) {
            putchar(s1[i]);
        }
    }
    return 0;
}
