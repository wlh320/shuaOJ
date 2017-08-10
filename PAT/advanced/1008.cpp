#include <cstdio>
int main()
{
    int curF = 0;
    int cost = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int f;
        scanf("%d", &f);
        if (curF < f) { // up
            cost += (f - curF) * 6; 
        } else if (curF > f) { // down
            cost += (curF - f) * 4;
        }
        cost += 5; // ??? 同一层再停5秒?
        curF = f;
    }
    printf("%d\n", cost);
    return 0;
}
