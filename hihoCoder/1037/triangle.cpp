#include <algorithm>
#include <cstdio>
using std::max;
int maze[101][101];
int dp[101][101];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            scanf("%d", &maze[i][j]);
        }
    }
    dp[0][0] = maze[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + maze[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + maze[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + maze[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[n - 1][i]);
    }
    printf("%d\n", ans);
    return 0;
}
