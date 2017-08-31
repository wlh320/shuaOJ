// 经典问题:最大子串和-Kadane算法
#include <cstdio>
int a[10001];
int main()
{
    int n;
    scanf("%d", &n);
    int maxsum = -1, l = 0, r = 0, tmp = 0, tl = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) flag = true;
        tmp += a[i];
        if (tmp > maxsum) {
            l = tl;
            r = i;
            maxsum = tmp;
        }
        if (tmp < 0) { // 重置为0
            tmp = 0;
            tl = i+1;
        }
    }
    if (flag) {
        printf("%d %d %d\n", maxsum, a[l], a[r]);
    } else {
        printf("%d %d %d\n", 0, a[0], a[n-1]);
    }
    return 0;
}
