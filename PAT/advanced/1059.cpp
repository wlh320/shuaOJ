#include <cstdio>
#include <cmath>
#define L unsigned long int
bool isPrime(L n)
{
    if (n <= 1) return false;
    for(L i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}
L nextP(L n)
{
    L next = n + 1;
    while(!isPrime(next)) next++;
    return next;
}
int main()
{
    bool flag = false;
    L n;
    L p = 2, e = 0;
    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1) {printf("1");return 0;}
    if (isPrime(n)) {printf("%ld", n);return 0;}
    while(n != 1) {
        while(n%p == 0) {
            n /= p;
            e++;
        }
        if (e) {
            if (flag)  printf("*"); else flag = true;
            printf("%ld", p);
            if (e > 1) printf("^%ld", e);
        }
        p = nextP(p);
        e = 0;
    }
    return 0;
}
