#include <cstdio>
int a[5];
int exist[5];
int m = 1;
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    {
        int n;
        scanf("%d", &n);
        switch(n % 5) {
            case 0: if (n % 2 == 0) {a[0] += n;exist[0]++;} break;
            case 1: a[1] += m*n; m*= -1; exist[1]++;break;
            case 2: a[2] += 1; exist[2]++;break;
            case 3: a[3] += n; exist[3]++; break;
            case 4: a[4] = (n > a[4]? n : a[4]);exist[4]++; break;
            default:break;
        }
    }
    for(int i = 0; i < 4; ++i) {
        if (!exist[i]) {printf("N ");}
        else {
            if (i == 3) {printf("%.1f ", float(a[i])/float(exist[3]));}
            else {printf("%d ", a[i]);}
        }
    }
    if (!exist[4])
        printf("N\n");
    else
        printf("%d\n", a[4]);
    return 0;
}
