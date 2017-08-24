// 编程之美面试题-数1问题 
// 我的第一想法是递归不是这个最优的,看到了这个算法感觉很牛妹想到
#include <cstdio>
int count(int x)
{
    int res = 0; // result
    int b = 1; // base
    int l, n, r; // left now right
    while(x / b) {
        l = x / (b*10);
        n = (x / b) % 10;
        r = x % b;
        if (n == 0) {
            res += l * b;
        } else if (n == 1) {
            res += l * b + r + 1;
        } else {
            res += (l+1) * b;
        }
        // printf("%d: %d %d %d\n", b, l, n, r);
        b *= 10;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", count(n));
    return 0;
}
