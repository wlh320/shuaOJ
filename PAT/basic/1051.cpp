#include <cstdio>
#include <cmath>
int main()
{
    double r1, p1, r2, p2;
    double a1, b1, a2, b2;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    a1 = r1 * cos(p1);
    b1 = r1 * sin(p1);
    a2 = r2 * cos(p2);
    b2 = r2 * sin(p2);
    double a = a1*a2 - b1*b2;
    double b = a1*b2 + a2*b1;
    if (fabs(a) < 1e-2) {
        a = 0;
    }
    if (fabs(b) < 1e-2) {
        b = 0;
    }
    if (fabs(a) < 1e-6 && fabs(b) < 1e-6)
        printf("0\n");
    else
        printf("%.2lf%+.2lfi\n", a, b);
    return 0;
}
