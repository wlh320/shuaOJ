#include <cstdio>
#include <cstring>
struct Time
{
    int h;
    int m;
    int s;
};
int cmp(Time a, Time b)
{
    if (a.h != b.h) {
        return a.h - b.h;
    } else {
        if (a.m != b.m) {
            return a.m - b.m;
        } else {
            return a.s - b.s;
        }
    }
}
int main()
{
    int n;
    Time max={0,0,0}, min={100,100,100};
    char maxName[16];
    char minName[16];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        char name[16];
        Time in, out;
        scanf("%s %d:%d:%d %d:%d:%d", name, 
        &in.h, &in.m, &in.s, &out.h, &out.m, &out.s);
        if (cmp(in, min) < 0) {
            min = in;
            strcpy(minName, name);
        }
        if (cmp(out, max) > 0) {
            max = out;
            strcpy(maxName, name);
        }
    }
    printf("%s %s\n", minName, maxName);
    return 0;
}
