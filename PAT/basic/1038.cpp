#include <cstdio>
int cnt[101];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int score;
        scanf("%d", &score);
        cnt[score]++;
    }
    int n_query;
    scanf("%d", &n_query);
    for(int i = 0; i < n_query; ++i) {
        int score;
        scanf("%d", &score);
        if (i == 0)
            printf("%d", cnt[score]);
        else
            printf(" %d", cnt[score]);
    }
    return 0;
}
