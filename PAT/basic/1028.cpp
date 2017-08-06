#include <cstdio>
#include <cstring>
struct Date
{
    int y;
    int m;
    int d;
    Date(int y, int m, int d) {this->y = y; this->m = m; this->d = d;}
};

bool elder(Date a, Date b)
{
    if (a.y < b.y) {
        return true;
    } else if (a.y == b.y && a.m < b.m) {
        return true;
    } else if (a.y == b.y && a.m == b.m && a.d < b.d) {
        return true;
    } else {
        return false;
    }
}

bool filter(Date a)
{
    if (elder(a, Date(1814,9,6))) // < 200year
        return true;
    else if (!elder(a, Date(2014, 9, 6)) && !(a.y==2014&&a.m==9&&a.d==6)) // >=
        return true;
    else
        return false;
}
int main()
{
    int n, val_n = 0;
    Date max(9999, 99, 99);
    Date min(0, 0, 0);
    char max_name[6];
    char min_name[6];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        char name[6];
        int y,m,d;
        scanf("%s %d/%d/%d", name, &y, &m, &d);
        Date tmp(y, m, d);
        if (!filter(tmp)) {
            if (elder(tmp, max)) {
                max = tmp;
                strcpy(max_name, name);
            }
            if (!elder(tmp, min)) {
                min = tmp;
                strcpy(min_name, name);
            }
            val_n++;
        }
    }
    if (val_n != 0)
        printf("%d %s %s\n", val_n, max_name, min_name);
    else
        printf("0\n");
    return 0;
}
