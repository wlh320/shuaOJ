// same as B-1034
#include <cmath>
#include <cstdio>
using namespace std;
#define LL long long
struct Number
{
    LL up;
    LL btm;
};

LL gcd(LL a, LL b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

Number simplify(Number a)
{
    LL g = gcd(abs(a.up), a.btm);
    if (g) {
        a.up /= g;
        a.btm /= g;
    }
    return a;
}

Number calc(Number a, char op, Number b)
{
    Number res;
    LL tmp;
    switch(op) {
    case '+':
        res.btm = a.btm * b.btm;
        res.up = a.up * b.btm + b.up * a.btm;
        break;
    case '-':
        res.btm = a.btm * b.btm;
        res.up = a.up * b.btm - b.up * a.btm;
        break;
    case '/': // /a = * 1/a
        tmp = b.up;
        b.up = b.btm;
        b.btm = tmp;
        if (tmp < 0) {
            b.btm *= -1;
            b.up *= -1;
        }
    case '*':
        res.up = a.up * b.up;
        res.btm = a.btm * b.btm;
        break;
    default:
        break;
    }
    if (res.btm)
        res = simplify(res);
    return res;
}
void print_n(Number a)
{
    if (a.btm == 0) {printf("Inf");return ;}
    if (a.up == 0) { printf("0"); return ;}
    LL tmp = abs(a.up);
    if (a.up < 0) {printf("(-");}
    if (a.up % a.btm == 0) {
        printf("%lld", tmp / a.btm);
    } else if (tmp / a.btm) {
        printf("%lld %lld/%lld", tmp / a.btm, tmp % a.btm, a.btm);
    } else {
        printf("%lld/%lld", tmp, a.btm);
    }
    if (a.up < 0) {printf(")");}
}
int main()
{
    char op[4] = {'+','-','*','/'};
    Number a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.btm, &b.up, &b.btm);
    a = simplify(a);
    b = simplify(b);
    for(LL i = 0; i < 4; ++i) {
        print_n(a);
        printf(" %c ", op[i]);
        print_n(b);
        printf(" = ");
        print_n(calc(a, op[i], b));
        printf("\n");
    }
    return 0;
}
