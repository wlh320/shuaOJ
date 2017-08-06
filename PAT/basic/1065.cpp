#include <cstdio>
int map[100000];// -1 absent| 0-99999 couple| -2 single
int main()
{
    for(int i = 0; i < 100000; ++i) {
        map[i] = -1;
    }
    int cp;
    scanf("%d", &cp);
    for(int i = 0; i < cp; ++i) {
        int cp1, cp2;
        scanf("%d %d", &cp1, &cp2);
        map[cp1] = cp2;
        map[cp2] = cp1;
    }
    int n;
    int dog = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int one;
        scanf("%d", &one);
        if (map[one] == -1) {
            map[one] = -2; // single
            dog++;
        } else if (map[one] >= 0 && map[one] <= 99999) {
            if (map[map[one]] == one) {
                map[one] = -2;
                dog++;
            } else if (map[map[one]] == -2) {
                map[map[one]] = -1;
                map[one] = -1;
                dog--;
            }
        }
    }
    printf("%d\n", dog);
    bool pflag = false;
    for(int i = 0; i < 100000; ++i) {
        if (map[i] == -2) {
            if (pflag) {
                printf(" %05d", i);
            } else {
                printf("%05d", i);
            }
            pflag = true;
        }
    }
    return 0;
}
