// 一个简单的暴力在线算法
#include <cstdio>
#include <map>
using namespace std;
int in[10004], pre[10004];
map<int, int> pos;

void lca(int il, int ir, int proot, int u, int v)
{
    if (il > ir) return ;
    int iroot = pos[pre[proot]];
    if (pos[u] < iroot && pos[v] < iroot) { // 在同一侧:左
        lca(il, iroot - 1, proot + 1, u, v);
    } else if (pos[u] > iroot && pos[v] > iroot) { // 在同一侧:右
        int rroot = proot + iroot - il + 1;
        lca(iroot + 1, ir, rroot, u, v);
    } else if (pos[u] < iroot && pos[v] > iroot) { // 两侧
        printf("LCA of %d and %d is %d.\n", u, v, pre[proot]);
    } else if (pos[u] > iroot && pos[v] < iroot) { // 两侧
        printf("LCA of %d and %d is %d.\n", u, v, pre[proot]);
    } else if (pre[proot] == u) {
        printf("%d is an ancestor of %d.\n", u, v);
    } else if (pre[proot] == v) {
        printf("%d is an ancestor of %d.\n", v, u);
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (pos.find(u) == pos.end() && pos.find(v) == pos.end()) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (pos.find(u) == pos.end()) {
            printf("ERROR: %d is not found.\n", u);
        } else if (pos.find(v) == pos.end()) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            lca(0, n-1, 0, u, v);
        }
    }
    return 0;
}

