#include <cstdio>
int main()
{
    int n;
    int loseA = 0, loseB = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int hanA, huaA, hanB, huaB;
        scanf("%d %d %d %d", &hanA, &huaA, &hanB, &huaB);
        if (huaA != huaB) {
            if ((hanA+hanB) == huaA) {
                loseB++;
            } else if ((hanA+hanB) == huaB) {
                loseA++;
            }
        }
    }
    printf("%d %d\n", loseA, loseB);
    return 0;
}
