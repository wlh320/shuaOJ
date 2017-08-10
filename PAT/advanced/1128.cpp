#include <cstdio>
int q[1001];
int main()
{
    int k;
    scanf("%d", &k);
    while(k--) {
        int n;
        bool flag = true;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &q[i]);
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                if (q[i]-q[j] == j-i || q[i]-q[j] == i-j || q[i] == q[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;

}
