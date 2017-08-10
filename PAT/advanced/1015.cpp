#include <cstdio>
#include <cmath>
bool isPrime(int n)
{
    if (n <= 1) 
        return false;
    int root = sqrt(n);
    for(int i = 2; i <= root; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool reversible(int n, int rdx) 
{
    int tmp = n;
    int revN = 0;
    while(tmp) {
        revN *= rdx;
        revN += (tmp % rdx);
        tmp /= rdx;
    }
    if (isPrime(n) && isPrime(revN)) {
        return true;
    }
    return false;
}

int main()
{
    int n, d;
    while(true) {
        scanf("%d", &n);
        if (n < 0) break;
        scanf("%d", &d);
        if (reversible(n, d)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
