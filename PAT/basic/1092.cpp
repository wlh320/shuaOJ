#include <cstdio>
int candi[1024];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);
            candi[j] += x;
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        if (candi[j] > ans) {
            ans = candi[j];
        }
    }
    printf("%d\n", ans);
    bool first = true;
    for (int j = 1; j <= n; j++) {
        if (candi[j] == ans) {
            if (!first) {
                printf(" ");
            }
            printf("%d", j);
            first = false;
        }
    }
    printf("\n");
    return 0;
}