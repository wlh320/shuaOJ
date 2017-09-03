// DFS 注意剪枝 不然会超时
// 上界的确定: 因为递增, 所以可以求出参数都相等时候的值
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
int n, k, p; // n = n1^p + ... + nk^p
int fpow(int a, int b) // 快速幂
{
    int r = 1;
    while(b) {
        if (b & 0x1) r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}
int tmp[400];
vector<int> ans;
void dfs(int num, int nf, int f)
{
    if (num < 0) return ;
    if (nf == 0) {
        if (num == 0) {
            ans.assign(tmp, tmp+k);
        }
        return ;
    }
    int ma = sqrt(double(num)/nf); // 确定搜索的上界很关键!
    for(int i = f; i <= ma; ++i) {
        tmp[nf-1] = i;
        dfs(num-fpow(i, p), nf-1, i);
    }
}
int main()
{
    scanf("%d %d %d", &n, &k, &p);
    dfs(n, k, 1);
    if (ans.size() == 0) {
        printf("Impossible\n");
    } else {
        printf("%d = ", n);
        for(int i = 0; i < ans.size(); ++i) {
            if (i != 0) printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }
    return 0;
}
