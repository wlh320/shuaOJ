#include <cstdio>
#include <vector>
using namespace std;
struct Node
{
    int n; // n sons
    int p; // parent
    vector<int> son;
    Node(){n=0;p=-1;}
};
Node t[100];
int lvls; // 共多少层
int cnt[100]; // 每层个数

void dfs(int root, int lvl)
{
    if (!t[root].n) { // leaf node
        cnt[lvl]++;
        lvls = lvl > lvls ? lvl:lvls;
    }
    for(int i = 0; i < t[root].n; ++i) {
        dfs(t[root].son[i], lvl+1);
    }
}

int main()
{
    int n, m; // n-node m-nonleaf
    scanf("%d %d", &n, &m);
    int id, k, tmp;
    for(int _ = 0; _ < m; ++_) {
        scanf("%d %d", &id, &k);
        t[id].n = k;
        for(int i = 0;i < k; ++i) {
            scanf("%d", &tmp);
            t[id].son.push_back(tmp);
            t[tmp].p = id;
        }
    }
    int root = tmp;
    while(t[root].p != -1) root = t[root].p;
    
    dfs(root, 0);
    for(int i = 0; i <= lvls; ++i) {
        if (i != 0) printf(" ");
        printf("%d", cnt[i]);
    }
    return 0;
}
