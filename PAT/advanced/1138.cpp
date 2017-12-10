// 树的各种简单遍历
#include <cstdio>
int pre[50001];
int in[50001];

void solve(int pl, int pr, int il, int ir)
{
    if (pl == pr) {
        printf("%d\n", pre[pr]);
        return;
    }
    int idx = il;
    for (idx = il; idx <= ir; ++idx) {
        if (in[idx] == pre[pl]) {
            break;
        }
    }
    if (idx == il) {
        // no left child
        solve(pl + 1, pr, il + 1, ir);
    } else {
        // go left child
        solve(pl + 1, pl + idx - il, il, idx - 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    solve(0, n - 1, 0, n - 1);
    return 0;
}
