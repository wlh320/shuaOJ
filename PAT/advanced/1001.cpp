#include <cstdio>
#include <cmath>
void formatPrint(int a)
{
    if (a < 0) {
        printf("-");
    }
    a = std::abs(a);
    if (a == 0) {
        printf("0\n");
        return ;
    }
    int f[4] = {-1, -1, -1, -1}; // -2,000,000 - 2,000,000
    for(int i = 0; i < 3; ++i) {
        if (a != 0) {
            f[i] = a % 1000;
        }
        a /= 1000;
    }
    for(int i = 2; i >= 0; --i) {
        if (f[i] != -1) {
            if(f[i+1] == -1) {
                printf("%d", f[i]);
            } else {
                printf("%03d", f[i]);
            }
            if (i != 0) {
                printf(",");
            }
        }
    }
    printf("\n");
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    formatPrint(sum);
    return 0;
}
