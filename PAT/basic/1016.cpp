#include <cstdio>
int main()
{
    char a[12];
    char b[12];
    char da, db;
    scanf("%s %c %s %c", a, &da, b, &db);
    int pa = 0, pb = 0;
    for(int i = 0; a[i]; ++i) {
        if (a[i] == da) {
            pa *= 10;
            pa += da-'0';
            
        }
    }
    for(int i = 0; b[i]; ++i) {
        if (b[i] == db) {
            pb *= 10;
            pb += db-'0';
        }
    }
    printf("%d\n", pa+pb);
    return 0;
}
