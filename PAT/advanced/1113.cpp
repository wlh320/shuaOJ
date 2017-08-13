#include <cstdio>
#include <algorithm>
int num[100001];
int main()
{
    int n, i;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    std::sort(num, num+n);
    int n1 = n / 2;
    int sum1 = 0;
    int sum2 = 0;
    for(i = 0; i < n1; ++i) {
        sum1 += num[i];
    }
    for(i = n1; i < n; ++i) {
        sum2 += num[i];
    }
    printf("%d %d\n", n%2, sum2-sum1);
    return 0;
}
