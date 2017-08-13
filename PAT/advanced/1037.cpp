#include <cstdio>
#include <algorithm>
int c[100000];
int p[100000];
int main()
{
    int nc, np;
    int sum = 0;
    scanf("%d", &nc);
    for(int i = 0; i < nc; ++i) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &np);
    for(int i = 0; i < np; ++i) {
        scanf("%d", &p[i]);
    }
    std::sort(c, c+nc);
    std::sort(p, p+np);
    int pc = 0, pp = 0;
    while(pc < nc && pp < np) {
        if (c[pc] < 0 && p[pp] < 0) {
            sum += c[pc] * p[pp];
            pc++;pp++;
        } else {
            break;
        }
    }
    pc = nc-1; pp = np-1;
    while(pc >= 0 && pp >= 0) {
        if (c[pc] > 0 && p[pp] > 0) {
            sum += c[pc] * p[pp];
            pc--;pp--;
        } else {
            break;
        }
    }
    printf("%d\n", sum);
    return 0;
}
