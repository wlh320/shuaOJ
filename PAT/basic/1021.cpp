#include <cstdio>
char n[1024];
int cnt[10];
int main()
{
    scanf("%s", n);
    for(int i = 0; n[i]; ++i)
        cnt[n[i]-'0']++;

    for(int i = 0; i < 10; ++i)
        if (cnt[i] != 0 )
            printf("%d:%d\n", i, cnt[i]);

    return 0;
}
