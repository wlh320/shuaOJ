#include <cstdio>
#include <cstring>
int max = 0;
char str[1024];
void test(int l, int r)
{
    int L = l, R = r;
    while(l < r) {
        if (str[l] != str[r]) break;
        l++;
        r--;
    }
    if (l >= r) {
        max = R-L+1 > max ? R-L+1 : max;
    }
}
int main()
{
    fgets(str, 1024, stdin);
    int len = strlen(str) - 1;
    str[len] = '\0'; // fgets get a '\n'
    for(int i = 0; i < len; ++i) {
        for(int j = len-1; j >= i; --j) {
            if (str[j] == str[i]) {
                test(i,j);
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
