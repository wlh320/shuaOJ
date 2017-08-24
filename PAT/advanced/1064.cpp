// 完全二叉树用数组存储的方法
#include <cstdio>
#include <algorithm>
int num[1001];
int t[1001];
int cnt = 0;
int n;
void inBuild(int idx)
{
    if (idx > n) return ;
    inBuild(2*idx); // left child
    t[idx] = num[cnt++];
    inBuild(2*idx+1); // right child
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    std::sort(num, num+n);
    inBuild(1);
    for(int i = 1; i <= n; ++i) {
        if (i != 1) { putchar(' ');}
        printf("%d", t[i]);
    }
    return 0;
}
