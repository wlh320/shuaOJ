#include <algorithm>
#include <cstdio>
using std::max;
int need[500];
int val[500];
int dp[10005];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &need[i], &val[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= need[i]; --j) {
            dp[j] = max(dp[j], dp[j - need[i]] + val[i]);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
