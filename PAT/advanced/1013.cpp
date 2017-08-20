// 并查集求连通子图个数
#include <cstdio>
int uset[1001];
int arc[1000*500][2];
void init(int n)
{
    for(int i = 1; i <= n; ++i)
        uset[i] = i;
}
int find(int x)
{
    int p = x;
    while(uset[p] != p) p = uset[p];
    int a = x, b;
    while(a != p) {
        b = uset[a];
        uset[a] = p;
        a = b;
    }
    return p;
}
void join(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y) {
        uset[x] = y;
    }
}
int main()
{
    int nV, nA, nQ; // vertex, arc, query
    scanf("%d %d %d", &nV, &nA, &nQ);
    for(int i = 0; i < nA; ++i) {
        scanf("%d %d", &arc[i][0], &arc[i][1]);
    }
    while(nQ--) {
        int tmp;
        scanf("%d", &tmp);
        init(nV);
        for(int i = 0; i < nA; ++i) {
            if (arc[i][0] != tmp && arc[i][1] != tmp) {
                join(arc[i][0], arc[i][1]); // 并
            }
        }
        int cnt = 0;
        for(int i = 1; i <= nV; ++i) {
            if (uset[i] == i) { // 连通子图个数
                cnt++;
            }
        }
        printf("%d\n", cnt-2); // tmp不算了, cnt-1条边互联
    }
    return 0;
}
