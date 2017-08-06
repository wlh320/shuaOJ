#include <cstdio>
bool cnt[10001];
bool num[101];

int main()
{
    int sum;
    scanf("%d", &sum);
    for(int i = 0; i <=100; ++i) {
        cnt[i] = true;
        num[i] = false;
    }
    while(sum--)
    {
        int n;
        scanf("%d", &n);
        num[n] = true;
        while(n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = (3*n+1)/2;
            cnt[n] = false;
        }
    }
    bool first = true;
    for(int i = 100; i >= 1; --i)
    {
        if (num[i] && cnt[i]) 
        {
            if (first) {
                printf("%d", i);
                first = false;
            } else {
                printf(" %d", i);
            }
        }
    }
    return 0;
}
