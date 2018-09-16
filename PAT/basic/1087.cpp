#include <cstdio>
bool note[20000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int s = i / 2 + i / 3 + i / 5;
        note[s] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 20000; i++) {
        if (note[i]) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
