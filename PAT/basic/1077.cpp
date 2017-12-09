#include <algorithm>
#include <cstdio>
int main()
{
    int n, full;
    scanf("%d %d\n", &n, &full);
    for (int i = 0; i < n; ++i) {
        int min_s = full + 1, max_s = -1;
        int n_stu = 0;
        int sum = 0;
        int t_score = 0;
        scanf("%d", &t_score);
        for (int j = 0; j < n - 1; ++j) {
            int score;
            scanf("%d", &score);
            if (score >= 0 && score <= full) {
                min_s = std::min(min_s, score);
                max_s = std::max(max_s, score);
                n_stu++;
                sum += score;
            }
        }
        sum -= (min_s + max_s);
        double s_score = double(sum) / (n_stu - 2);
        printf("%d\n", int((s_score + t_score) / 2 + 0.5));
    }
    return 0;
}
