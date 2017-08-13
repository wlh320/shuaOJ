#include <cstdio>
#include <cstdlib>
int dis[100002]; // from 1 to n
int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
        dis[i+2] = sum;
    }
    int nQ;
    int from, to, d;
    scanf("%d", &nQ);
    for(int i = 0; i < nQ; ++i) {
        scanf("%d %d", &from, &to);
        d = abs(dis[from]-dis[to]);
        if (sum-d < d) {
            d = sum-d;
        }
        printf("%d\n", d);
    }
    return 0;
}
