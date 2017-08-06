#include <cstdio>
int cal[64];
int main()
{
    int cnt = 0;
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        scanf("%d", &num);
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        if (cal[sum]) {
            cal[sum]++;
        } else {
            cal[sum]++;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    bool pflag = false;
    for(int i = 0; i < 64; ++i) {
        if (cal[i] != 0) {
            if (pflag)
                printf(" %d", i);
            else
                printf("%d", i);
            pflag = true;
        }
    }
    return 0;
}
