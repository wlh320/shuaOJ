// 判断是否连通图(DFS/BFS/并查集)
#include <cstdio>
enum Tp {NON=0, SEMI=1, EU=2};
const char *tStr[3] = {"Non-Eulerian", "Semi-Eulerian", "Eulerian"};
int dgr[501];
int uset[501];
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
Tp check(int nV)
{
    int odd = 0;
    int cnt = 0;
    for(int i = 1; i <= nV; ++i) {
        if (uset[i] == i) cnt++;
    }
    if (cnt != 1) return NON;
    for(int i = 1; i <= nV; ++i) {
        if (dgr[i] % 2 != 0) odd++;
    }
    if (odd == 0) return EU;
    else if (odd == 2) return SEMI;
    else return NON;
}
int main()
{
    int nV, nA;
    scanf("%d %d", &nV, &nA);
    for(int i = 1; i <= nV; ++i)
        uset[i] = i;
    for(int i = 0; i < nA; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        dgr[v1]++;
        dgr[v2]++;
        uset[find(v1)] = find(v2);
    }
    for(int i = 1; i <= nV; ++i) {
        if(i != 1) printf(" ");
        printf("%d", dgr[i]);
    }
    printf("\n");
    printf("%s\n", tStr[check(nV)]);
    return 0;
}
