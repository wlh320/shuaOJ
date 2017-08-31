// dp 寻找子序列和等于目标值
#include <cstdio>
#include <algorithm>
using namespace std;
int coin[10001];
int dp[10001];
bool flag[10001][10001];
bool cmp(int a, int b) 
{
    return a > b;
}
int main()
{
    int n, tgt;
    scanf("%d %d", &n, &tgt);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &coin[i]);
    }
    sort(coin, coin+n, cmp);
    for(int i = 0; i < n; ++i) {
        for(int j = tgt; j >= coin[i]; --j) {
            if (dp[j] <= dp[j-coin[i]] + coin[i]) {
                flag[i][j] = true;
                dp[j] = dp[j-coin[i]] + coin[i];
            }
        }
    }
    bool first = true;
    if (dp[tgt] != tgt) {
        printf("No Solution\n");
    } else {
        while(tgt > 0) { // 输出选中的硬币
            if (flag[n][tgt]) {
                if(!first) printf(" ");
                printf("%d", coin[n]);
                first = false;
                tgt -= coin[n];
            }
            n--;
        }
    }
    return 0;
}
