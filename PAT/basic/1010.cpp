#include <cstdio>
int main()
{
    int a, n; // ax^n
    bool flag=true;
    while(scanf("%d %d", &a, &n) != EOF)
    {
        a = a * n;
        if (n != 0)
            n = n - 1;
        if (!(n == 0 && a == 0))
        {
            if (flag)
            {
                printf("%d %d", a, n);
                flag = false;
            } else 
                printf(" %d %d", a, n);
        }
        if (flag)
            printf("0 0\n");
    }

    return 0;
}
