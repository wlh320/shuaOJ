#include <cstdio>
int main()
{
    int gsk1[3], gsk2[3];
    int sum[3];
    scanf("%d.%d.%d", &gsk1[0], &gsk1[1], &gsk1[2]);
    scanf("%d.%d.%d", &gsk2[0], &gsk2[1], &gsk2[2]);
    sum[2] = gsk1[2] + gsk2[2];
    sum[1] = gsk1[1] + gsk2[1] + sum[2] / 29;
    sum[0] = gsk1[0] + gsk2[0] + sum[1] / 17;
    sum[2] %= 29;  
    sum[1] %= 17;
    printf("%d.%d.%d\n",sum[0], sum[1], sum[2]);
    return 0;
}
