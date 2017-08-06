#include <cstdio>
bool block[256];
char input[100001];
char broken[256];
int main()
{
    fgets(broken, 256, stdin);
    for(int i = 0; broken[i]; ++i) {
        if (broken[i] == '+') {
            for(char j = 'A'; j <= 'Z'; ++j) {
                block[j] = true;
            }
        } else {
            if (broken[i] >= 'A' && broken[i] <= 'Z') {
                block[broken[i]] = true;
                block[broken[i]-'A'+'a'] = true;
            } else {
                block[broken[i]] = true;
            }
        }
    }
    fgets(input, 100001, stdin);
    for(int i = 0; input[i]; ++i) {
        if(!block[input[i]]) {
            printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}
