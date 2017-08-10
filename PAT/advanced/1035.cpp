#include <cstdio>
char from[5] = {0, '1', '0', 'l', 'O'};
char to[5]   = {0, '@', '%', 'L', 'o'};
int map[256];
struct Team
{
    char name[11];
    char pswd[11];
    bool flag;
};
Team t[1000];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < 5; ++i) {
        map[from[i]] = i;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%s %s", t[i].name, t[i].pswd);
        for(int j = 0; t[i].pswd[j]; ++j) {
            if(map[t[i].pswd[j]]) {
                t[i].pswd[j] = to[map[t[i].pswd[j]]];
                t[i].flag = true;
            }
        }
        if (t[i].flag) {
            cnt++;
        }
    }
    if(cnt == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified\n");
        } else {
            printf("There are %d accounts and no account is modified\n", n);
        }
    } else {
        printf("%d\n", cnt);
        for(int i = 0; cnt; ++i) {
            if (t[i].flag) {
                printf("%s %s\n", t[i].name, t[i].pswd);
                cnt--;
            }
        }
    }
    return 0;

}
