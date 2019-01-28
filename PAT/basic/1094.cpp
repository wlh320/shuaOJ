#include <cmath>
#include <cstdio>
char n[1024];
bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}
int main()
{
    int l, k;
    scanf("%d %d", &l, &k);
    scanf("%s", n);
    bool found = false;
    for (int i = 0; i < l - k + 1; i++) {
        int x = 0;
        bool leading = true;
        int leading_zero = 0;
        for (int j = 0; j < k; j++) {
            x *= 10;
            x += (n[i + j] - '0');
            if (leading && n[i + j] == '0') {
                leading_zero++;
            }
            if (n[i + j] != '0') {
                leading = false;
            }
        }
        if (is_prime(x)) {
            found = true;
            for (int i = 0; i < leading_zero; i++) {
                printf("0");
            }
            printf("%d\n", x);
            break;
        }
    }
    if (!found) {
        printf("404\n");
    }
    return 0;
}