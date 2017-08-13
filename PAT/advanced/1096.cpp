// something wrong
#include <cstdio>
int main()
{
    int n;
    int maxi, max = 0;
    scanf("%d", &n);
    long long int prod;
    for(int i = 2; i < 50; ++i) {
        prod = 1;
        for(int j = i; j <= 50; ++j) {
            prod *= j;
            if (n % prod == 0) {
                if ((j-i+1) > max) {
                    max = j-i+1;
                    maxi = i;
                }
            }
        }
    }
    if (max == 0) { // prime
        printf("1\n%d", n);
    } else if (max == 1) { // 1 factor
        printf("1\n%d", maxi);
    } else {
        printf("%d\n", max);
        for(int k = maxi; k < maxi+max; ++k) {
            if (k != maxi) printf("*");
            printf("%d", k);
        }
    }
    return 0;
}
