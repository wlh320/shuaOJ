#include <cstdio>
#define LL long long int
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i) {
        LL a, b, c, sum;
        scanf("%lld %lld %lld", &a, &b, &c);
        sum = a + b;
        if (a > 0 && b > 0 && sum <= 0) { // overflow
            printf("Case #%d: true\n", i+1);
        } else if (a < 0 && b < 0 && sum >= 0) { // overflow
            printf("Case #%d: false\n", i+1);
        } else {
            printf("Case #%d: %s\n", i+1, (sum > c)?"true":"false");
        }
    }
    return 0;
}
