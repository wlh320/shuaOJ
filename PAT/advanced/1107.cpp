#include <cstdio>
#include <algorithm>
int pp[1001];// key-hobby value-people
int uset[1001];
int cnt[1001];
bool cmp(int a, int b){return a>b;}
int find(int x)
{
    int pre = x;
    while(uset[pre] != pre) {
        pre = uset[pre];
    }
    int p = x, q; // 路径压缩
    while(p != pre) { 
        q = uset[p];
        uset[p] = pre;
        p = q;
    }
    return pre;
}
void join(int a, int b)
{
    int ai = find(a);
    int bi = find(b);
    if (ai != bi) {
        uset[ai] = bi;
    }
}
int main()
{
    for(int i = 1; i <= 1000; ++i) uset[i] = i;
    int n;
    scanf("%d", &n);
    int nh, hb;
    for(int i = 1; i <= n; ++i) {
        scanf("%d:", &nh);
        for(int j = 0; j < nh; ++j) {
            scanf("%d", &hb);
            if (pp[hb]) {
                join(i, pp[hb]);
            } else {
                pp[hb] = i;
            }
        }
    }
    int nG = 0;
    for(int i = 1; i <= n; ++i) {
        int x = find(i);
        if (x == i) nG++;
        cnt[x]++;
    }
    printf("%d\n", nG);
    std::sort(cnt, cnt+n+1, cmp);
    for(int i = 0; i < nG; ++i) {
        if (i == 0) {
            printf("%d", cnt[i]);
        } else {
            printf(" %d", cnt[i]);
        }
    }
    printf("\n");
    return 0;
}
