// 多叉树DFS
#include <cstdio>
#include <vector>
using namespace std;
struct Node
{
    int n;
    vector<int> son;
};
Node t[100];
int lvl; // 总层数
int cnt[101]; // 计数

void dfs(int r, int l) // root, level
{
    lvl = l > lvl ? l : lvl;
    cnt[l]++;
    for(int i = 0; i < t[r].n; ++i) {
        dfs(t[r].son[i], l+1);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int k, id, tmp;
    while(m--) {
        scanf("%d %d", &id, &k);
        t[id].n = k;
        for(int i = 0; i < k; ++i) {
            scanf("%d", &tmp);
            t[id].son.push_back(tmp);
        }
    }
    int root = 01;
    dfs(root, 1);
    int maxI = 1;
    for(int i = 2; i <= lvl; ++i) {
        if (cnt[i] > cnt[maxI]) {
            maxI = i;
        }
    }
    printf("%d %d\n", cnt[maxI], maxI);
    return 0;
}
