#include <cstdio>
char a[1001];
char q[1001];
int b;
int r;
int main()
{
    scanf("%s %d", a, &b);
    int i,j;
    for(i = 0, j = 0; a[i]; ++i) {
        r = r * 10;
        r += a[i] - '0';
        q[j++] = (r / b) + '0';
        r = r % b;
    }
    q[j] = '\0';
    i = 0;
    if(j != 1)
        for(i = 0; q[i]=='0'; ++i);
    printf("%s %d\n", q+i, r);
    return 0;
}
