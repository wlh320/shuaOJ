#include <cstdio>
#define CLK_TCK 100
int main()
{
    int start, end;
    scanf("%d %d", &start, &end);
    int itvl = (end - start) / CLK_TCK;
    int h,m,s;
    s = itvl % 60;
    itvl /= 60;
    m = itvl % 60;
    h = itvl / 60;
    if ((end - start) % CLK_TCK >= (CLK_TCK / 2)) {
        s += 1; // +1s
    }
    printf("%02d:%02d:%02d\n", h,m,s);
    return 0;
}
