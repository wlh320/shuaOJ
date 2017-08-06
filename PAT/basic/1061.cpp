#include <cstdio>
int score[100];
int ans[100];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &score[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &ans[i]);
    }
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < m; ++j) {
            int myans;
            scanf("%d", &myans);
            if (myans == ans[j]) {
                sum += score[j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
