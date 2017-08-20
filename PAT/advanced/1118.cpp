// union find
#include <cstdio>
int u[10001];
int shown[10001];
int find(int x)
{
    int pre = x;
    while(u[pre] != pre) {
        pre = u[pre];
    }
    int p = x, q; // 路径压缩
    while(p != pre) { 
        q = u[p];
        u[p] = pre; 
        p = q;
    }
    return pre;
}

void join(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y) {
        u[x] = y;
    }
}

int main()
{
    for(int i = 0; i < 10001; ++i) u[i] = i;
    int n, np;
    scanf("%d", &n);
    int pre, tmp;
    for(int i = 0; i < n; ++i) {
        scanf("%d",&np);
        pre = 0;
        for(int j = 0; j < np; ++j) {
            scanf("%d", &tmp);
            if (pre) {
                join(pre, tmp);
            }
            pre = tmp;
            shown[tmp] = true;
        }
    }
    int cntN = 0, cntC = 0;
    for(int i = 1; i < 10001; ++i) {
        if (shown[i]) {
            cntN++;
            if (find(i) == i) {
                cntC++;
            }
        }
    }
    printf("%d %d\n", cntC, cntN);
    int nq;
    scanf("%d", &nq);
    for(int i = 0; i < nq; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (find(a) == find(b)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
