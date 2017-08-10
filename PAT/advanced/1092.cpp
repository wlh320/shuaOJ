// same as B-1039
#include <cstdio>
int cnt[128];
char all[1001];
char want[1001];
int main()
{
    scanf("%s", all);
    scanf("%s", want);
    for(int i = 0; all[i]; ++i)
        cnt[all[i]]++;
    for(int i = 0; want[i]; ++i)
        cnt[want[i]]--;

    int sum_p = 0, sum_m = 0;
    for(int i = 0; i < 128; ++i) {
        if (cnt[i] > 0) sum_p+=cnt[i];
        else if (cnt[i] < 0) sum_m-=cnt[i];
    }
    if (sum_m) {
        printf("No %d\n", sum_m);
    } else {
        printf("Yes %d\n", sum_p);
    }
    return 0;
}
