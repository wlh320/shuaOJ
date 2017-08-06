#include <cstdio>
int score_sum[100001];
int main()
{
    int n;
    int max_ind = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int school, score;
        scanf("%d %d", &school, &score);
        score_sum[school] += score;
        if (score_sum[school] > score_sum[max_ind]) {
            max_ind = school;
        }
    }
    printf("%d %d", max_ind, score_sum[max_ind]);
    return 0;
}
