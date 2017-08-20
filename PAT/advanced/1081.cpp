#include <cstdio>
#include <cmath>
#define LL long long int
struct Num
{
    LL nu;
    LL de;
    Num(){nu=0;de=1;}
};

LL gcd(LL a, LL b) 
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

Num simplify(Num a)
{
    if (a.nu == 0) {
        a.de = 1;
        return a;
    }
    LL g = gcd(a.nu, a.de);
    a.nu /= g;
    a.de /= g;
    return a;
}

Num add(Num a, Num b)
{
    LL g  = gcd(a.de, b.de);
    LL be = a.de * b.de / g;
    a.nu = a.nu*be/a.de + b.nu*be/b.de;
    a.de = be;
    return simplify(a);
}

int main()
{
    int n;
    scanf("%d", &n);
    Num sum, tmp;
    for(int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &tmp.nu, &tmp.de);
        tmp = simplify(tmp);
        sum = add(sum, tmp);
    }
    if(sum.nu < 0) {printf("-"); sum.nu *= -1;}
    if (sum.nu != 0) {
        if (sum.nu > sum.de) {
            printf("%lld", sum.nu / sum.de);
        }
        if (sum.nu % sum.de) {
            if (sum.nu > sum.de) printf(" ");
            printf("%lld/%lld", sum.nu % sum.de, sum.de);
        }
    } else {
        printf("0");
    }
    return 0;
}
