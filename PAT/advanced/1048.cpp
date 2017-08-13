#include <cstdio>
int coin[1001];
int main()
{
    int tmp;
    int nCoins, target;
    scanf("%d %d", &nCoins, &target);
    for(int i = 0; i < nCoins; ++i) { // 统计
        scanf("%d", &tmp);
        coin[tmp]++;
    }
    for(int i = 0; i < target; ++i) {
        if (coin[i]-- && coin[target-i]) {
            printf("%d %d\n", i, target-i);
            return 0;
        }
        coin[i]++; // 实际上没有必要加回去了,target-i一定不行
    }
    printf("No Solution\n");
    return 0;
}
