#include <cstdio>
#include <algorithm>
#define MAX 0
#define MIN 1
int reunion(int n, int type)
{
    int narr[4];
    for(int i = 0; i < 4; ++i) {
        narr[i] = n % 10;
        n /= 10;
    }
    int res = 0;
    std::sort(narr, narr+4);
    if (type == MAX) {
        for(int i = 3; i != -1; --i) {
            res *= 10;
            res += narr[i];
        }
    } else {
        for(int i = 0; i < 4; ++i) {
            res *= 10;
            res += narr[i];
        }
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    do {
        int max = reunion(n, MAX);
        int min = reunion(n, MIN);
        printf("%04d - %04d = %04d\n", max, min, max-min);
        n = max - min;
    } while(n != 6174 && n!= 0);
    return 0;
}
