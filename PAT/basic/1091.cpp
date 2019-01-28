#include <cstdio>
bool check(int n, int nk2)
{
    while (n) {
        if (n % 10 != nk2 % 10) {
            return false;
        }
        n /= 10;
        nk2 /= 10;
    }
    return true;
}
int main()
{
    int m;
    scanf("%d", &m);
    while (m--) {
        int k;
        bool no = true;
        scanf("%d", &k);
        for (int n = 1; n < 10; n++) {
            int nk2 = n * k * k;
            if (check(k, nk2)) {
                printf("%d %d\n", n, nk2);
                no = false;
                break;
            }
        }
        if (no) {
            printf("No\n");
        }
    }
    return 0;
}