// unsigned long long 两点不过, 需要大数加法
#include <cstdio>
#include <cstring>
void add(char *n)
{
    char tmp[100];
    int len = strlen(n);
    tmp[len] = '\0';
    for(int i = 0; n[i]; ++i) {
        tmp[len-i-1] = n[i];
    }
    int c = 0;
    for(int i = 0; i < len; ++i) {
        int sum = (n[i] + tmp[i] + c -'0'-'0');
        n[i] = sum % 10 + '0';
        c = sum / 10;
    }
    if (c != 0) {
        n[len] = c+'0';
        n[len+1] = '\0';
    }
}
bool isPalin(char n[100])
{
    int l = 0, r = strlen(n) - 1;
    while(l < r) {
        if (n[l] != n[r]) {
            return false;
        }
        l++;r--;
    }
    return true;
}
int main()
{
    char n[100];
    int k; int i;
    scanf("%s %d", n, &k);
    for(i = 0; i <= k; ++i) {
        if (isPalin(n)) {
            printf("%s\n%d\n", n, i);
            break;
        }
        if (i != k)
            add(n);
    }
    if (i > k) {
        for(int i = strlen(n)-1; i >= 0; --i) {
            putchar(n[i]);
        }
        printf("\n%d\n", k);
    }
    return 0;
}
