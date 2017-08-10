#include <cstdio>
#include <cstring>
bool isSame(int *cnt)
{
    for(int i = 0; i < 10; ++i) {
        if (cnt[i] != 0) {
            return false;
        }
    }
    return true;
}
int main()
{
    char num[21];
    int cnt[10] = {0};
    scanf("%s", num);
    int len = strlen(num);
    int c = 0;
    for(int i = len -1; i >= 0; --i) {
        cnt[num[i]-'0']++;
        int tmp = (num[i]-'0') * 2 + c;
        num[i] = (tmp % 10) + '0';
        cnt[num[i]-'0']--;
        c = tmp / 10;
    }
    if (c || !isSame(cnt)) { // 多出一位肯定不对
        printf("No\n");
        if (c != 0) putchar('0'+c);
    } else {
        printf("Yes\n");
    }
    printf("%s\n", num);
    return 0;
}
