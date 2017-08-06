#include <cstdio>
char str[100001];
int main()
{
    unsigned int N = 0;
    scanf("%[^\n]", str);
    for(int i = 0; str[i]; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            N += (str[i]-'a'+1);
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            N += (str[i]-'A'+1);
        }
    }
    int cnt1 = 0;
    int cnt0 = 0;
    while(N) {
        if (N % 2 == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
        N >>= 1;
    }
    printf("%d %d\n", cnt0, cnt1);
    return 0;
}
