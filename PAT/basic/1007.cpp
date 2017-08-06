#include <cstdio>
#include <cmath>

bool is_prime(int n)
{
    for(int i = 2; i <= int(sqrt(n)); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n, cnt=0;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        if (is_prime(i) && is_prime(i+2))
            if (i+2 <= n)
                cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
