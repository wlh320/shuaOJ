// dp 类似最长公共子序列问题, 不过这个的串中间可以重复多次
#include <cstdio>
#include <algorithm>
int eva[201]; // Eva's order
int clr[10001]; // all colors
int dp[201][10001]; // dp[i][j]- eva[i]~clr[j] max
int main()
{
    int n, m, l;
    scanf("%d", &n); // color range
    scanf("%d", &m); // eva's length
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &eva[i]);
    }
    scanf("%d", &l);
    for(int i = 1; i <= l; ++i) {
        scanf("%d", &clr[i]);
    }
    int len;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= l; ++j) {
            len = std::max(dp[i-1][j], dp[i][j-1]);
            len = std::max(len, dp[i-1][j-1]);
            if (eva[i] == clr[j]) len += 1;
            dp[i][j] = len;
        }
    }
    printf("%d\n", dp[m][l]);
    return 0;
}
