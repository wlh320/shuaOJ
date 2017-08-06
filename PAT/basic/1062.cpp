#include <cstdio>
#include <cmath>
struct Number
{
    int up;
    int btm;
    Number(int a=0, int b=0){up=a;btm=b;}
};
int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
int cmp(Number a, Number b)
{ // |- <|0 =|1 >|
    int res = a.up * b.btm - b.up * a.btm;
    return res;
}

int main()
{
    int k;
    Number l, r;
    scanf("%d/%d %d/%d %d", &l.up, &l.btm, &r.up, &r.btm, &k);
    bool pflag = false;
    if (cmp(l,r) > 0) {
        Number tmp = l;
        l = r;
        r = tmp;
    } 
    for(int i = 1; i <= k; ++i) {
        Number a(i,k);
        if (cmp(a,l) <= 0 || cmp(a,r) >= 0) {
            continue;
        }
        if (gcd(i, k) == 1) {
            if (pflag)
                printf(" %d/%d", i, k);
            else
                printf("%d/%d", i, k);
            pflag = true;
        }
    }
    printf("\n");
    return 0;
}
