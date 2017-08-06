#include <cstdio>

int sum[1001];

int main()
{
    int n;
    int n_team = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int no, tmp, score;
        scanf("%d-%d %d", &no, &tmp, &score);
        sum[no] += score;
    }
    int max = -1;
    int max_ind = 0;
    for(int i = 0; i < 1001; ++i) {
        if (sum[i] > max) {
            max = sum[i];
            max_ind = i;
        }
    }
    printf("%d %d\n", max_ind, max);
    return 0;
}
