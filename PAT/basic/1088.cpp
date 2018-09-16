#include <cstdio>
#include <cmath>
int main()
{
    int m, x, y, i;
    scanf("%d %d %d", &m, &x, &y);
    int a, b;
    double c;
    for (i = 99; i >= 10; i--) {
        b = 10 * (i % 10) + i / 10;
        int d = std::abs(i - b);
        if (d * y  == b * x) {
            a = i;
            c = b * 1.0 / y;
            break;
        }
    }
    if (i < 10) {
        printf("No Solution\n");
        return 0;
    }
    printf("%d", a);
    printf(" %s", a > m ? "Cong": (a < m? "Gai": "Ping"));
    printf(" %s", b > m ? "Cong": (b < m? "Gai": "Ping"));
    printf(" %s\n", c > m ? "Cong": (c < m? "Gai": "Ping"));
    return 0;
}

