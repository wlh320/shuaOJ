#include <cstdio>
#include <cmath>
double mo(int a, int b)
{
    return sqrt(a*a+b*b);
}
int main()
{
    int n;
    int a, b;
    scanf("%d", &n);
    double max = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        double m = mo(a, b);
        max = m > max ? m : max;
    }
    printf("%.2lf\n", max);
    return 0;
}
