#include <cstdio>
int digit[64];
void print(int *d, int n)
{
    int i;
    for(i = n-1; i > 0; --i)
        printf("%d ", d[i]);
    printf("%d", d[i]);
}
int main()
{
    int idx = 0;
    
    int n, d;
    scanf("%d %d", &n, &d);
    while(n) {
        digit[idx++] = n % d;
        n /= d;
    }
    if (idx == 0) {
        printf("Yes\n0\n");
        return 0;
    }
    int head = 0, tail = idx - 1;
    while(head < tail) {
        if (digit[head++] != digit[tail--]) {
            printf("No\n");
            print(digit, idx);
            return 0;
        }
    }
    printf("Yes\n");
    print(digit, idx);
    return 0;
}
