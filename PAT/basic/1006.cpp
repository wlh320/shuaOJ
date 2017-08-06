#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    int b = n / 100;
    n %= 100;
    int s = n / 10;
    n %= 10;
    if (b) {
        for(int i = 0;i < b; ++i)
            printf("B");
    }
    if (s) {
        for(int i = 0;i < s; ++i)
            printf("S");
    }
    for(int i = 0; i < n; ++i)
        printf("%d", (i+1));
    printf("\n");
    return 0;
}
