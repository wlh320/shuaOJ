#include <cstdio>
#include <vector>
using namespace std;
bool g[1000][1000];
void check(int nv, vector<int>& v)
{
    for (unsigned int i = 0; i < v.size(); i++) {
        for (unsigned int j = i + 1; j < v.size(); j++) {
            if (!g[v[i]][v[j]]) {
                printf("Not a Clique\n");
                return;
            }
        }
    }
    for (int i = 1; i <= nv; i++) {
        unsigned int j;
        for (j = 0; j < v.size(); j++) {
            if (i == v[j]) { // 只找这个集合外的点
                break;
            } else if (!g[i][v[j]]) { // 这个点就不用再找了
                break;
            }
        }
        if (j >= v.size()) { // 找到一个点与这个集合的点全都连接
            printf("Not Maximal\n");
            return;
        }
    }
    printf("Yes\n");
}
int main()
{
    int nv, ne;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        g[from][to] = g[to][from] = true;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int cnt;
        scanf("%d", &cnt);
        vector<int> vexs(cnt);
        for (int j = 0; j < cnt; j++) {
            int id;
            scanf("%d", &id);
            vexs[j] = id;
        }
        check(nv, vexs);
    }
    return 0;
}
