#include <cstdio>
int main()
{
    int n;
    int max_id = 0, max_dis = -1;
    int min_id = 0, min_dis = 99999;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int id, x, y;
        scanf("%d %d %d", &id, &x, &y);
        int dis = x * x + y * y;
        if (dis < min_dis) {
            min_id = id;
            min_dis = dis;
        }
        if (dis > max_dis) {
            max_id = id;
            max_dis = dis;
        }
    }
    printf("%04d %04d\n", min_id, max_id);
    return 0;
}
