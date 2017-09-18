#include <cstdio>
#include <cstdlib>
#include <cstring>
const int ten[] = {1,10,100,1000,10000,100000,1000000};
int main()
{
    int n;
    scanf("%d", &n);
    int num, a, b;
    char str[16];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        sprintf(str, "%d", num);
        int split = strlen(str)/2;
        a = num / ten[split];
        b = num % ten[split];
        if (a == 0 || b == 0) {
            printf("No\n");
            continue;
        }
        if (num % (a*b) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
