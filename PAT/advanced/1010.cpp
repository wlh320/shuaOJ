#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long int
LL rdx2ten(char n[16], int radix)
{
    LL val = 0;
    int len = strlen(n);
    for(int i = 0; i < len; ++i) {
        val *= radix;
        if (n[i] >= '0' && n[i] <= '9') {
            val += (n[i]-'0');
        } else {
            val += (n[i]-'a'+10);
        }
        if (val < 0) {
            return -1;
        }
    }
    return val;
}
int main()
{
    char n1[16];
    char n2[16];
    int tag, radix;
    scanf("%s %s %d %d", n1, n2, &tag, &radix);
    if (tag == 2) swap(n1, n2);

    LL valN1 = rdx2ten(n1, radix);

    LL minR = 0;
    LL maxR = valN1+1;
    LL midR;
    for(int i = 0; n2[i]; ++i) {
        minR = n2[i] > minR ? n2[i] : minR;
    }
    if (minR >= '0' && minR <= '9') {
        minR = minR-'0'+1;
    } else if (minR >= 'a' && minR <= 'z') {
        minR = minR-'a'+10+1;
    }
    // 有一个点会超时,必须二分查找
    while(minR <= maxR) {
        midR = (minR+maxR) / 2;
        LL valN2 = rdx2ten(n2, midR);
        if (valN2 == -1 || valN2 > valN1) {
            maxR = midR - 1;
        } else if (valN2 < valN1) {
            minR = midR + 1;
        } else if (valN2 == valN1) {
            printf("%lld\n", midR);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}
