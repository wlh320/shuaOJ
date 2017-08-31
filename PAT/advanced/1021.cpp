// DFS求Grpah最深的深度, 求连通分量个数用的也是DFS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arc[10240]; // 邻接表
bool visit[10240];
int part;
int lvl;
int cnt[10240];
int dfs(int root, int l)
{
    visit[root] = true;
    lvl = max(l, lvl);
    for(int i = 0; i < arc[root].size(); ++i) {
        if (!visit[arc[root][i]]) {
            dfs(arc[root][i], l+1);
        }
    }
    return lvl;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    for(int i = 0; i < n-1; ++i) {
        scanf("%d %d", &a, &b);
        arc[a].push_back(b);
        arc[b].push_back(a);
    }
    int maxcnt = 0;
    int comp = 0;
    for(int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            comp++;
            dfs(i, 0);
        }
    }
    if (comp != 1) {
        printf("Error: %d components\n", comp);
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        lvl = 0;
        for(int j = 1; j <= n; ++j) visit[j] = false;
        cnt[i] = dfs(i, 0);
        maxcnt = max(maxcnt, lvl);
    }
    for(int i = 1; i <= n; ++i) {
        if (cnt[i] == maxcnt) {
            printf("%d\n", i);
        }
    }
    return 0;
}
