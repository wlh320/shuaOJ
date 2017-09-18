#include <cstdio>
int main()
{
    int money, n;
    scanf("%d %d", &money, &n);
    int n1, b, t, n2;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if (money == 0) {
            printf("Game Over.\n");
            break;
        }
        if (money < t) {
            printf("Not enough tokens.  Total = %d.\n", money);
        } else if (n1 < n2 && b == 1) {
            money += t;
            printf("Win %d!  Total = %d.\n", t, money);
        } else if (n1 > n2 && b == 0) {
            money += t;
            printf("Win %d!  Total = %d.\n", t, money);
        } else {
            money -= t;
            printf("Lose %d.  Total = %d.\n", t, money);
        }
    }
    return 0;
}
