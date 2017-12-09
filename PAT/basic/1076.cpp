#include <cstdio>
int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 4; ++j) {
            char op = getchar();
            getchar();
            char flag = getchar();
            getchar();
            if (flag == 'T') {
                printf("%d", int(op - 'A' + 1));
            }
        }
    }
    printf("\n");
    return 0;
}
