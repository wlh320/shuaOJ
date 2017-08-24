// DFS遍历树的所有路径求和
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Node
{
    int n;
    int p;
    vector<int> son;
    Node(): n(0), p(-1) {}
};
Node t[100];
int w[100];
int target;
stack<int> s;
bool cmp(int a, int b){return w[a] > w[b];}
void dfs(int root, int sum)
{   
    if (sum+w[root] > target) { //pruning
        return ;
    }
    if (t[root].n == 0 && sum+w[root] == target) { // leaf
        int p = root;
        while(p != -1) {
            s.push(w[p]);
            p = t[p].p;
        }
        while(!s.empty()) {
            printf("%d", s.top());
            if (s.size() != 1) printf(" ");
            s.pop();
        }
        printf("\n");
    }
    for(int i = 0; i < t[root].n; ++i) {
        dfs(t[root].son[i], sum + w[root]);
    }
}
int main()
{
    int n, m;
    scanf("%d %d %d", &n, &m, &target);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    int id, k, tmp;
    for(int _ = 0; _ < m; ++_) {
        scanf("%d %d", &id, &k);
        t[id].n = k;
        for(int i = 0; i < k; ++i) {
            scanf("%d", &tmp);
            t[id].son.push_back(tmp);
            t[tmp].p = id;
        }// sort by weight
        sort(t[id].son.begin(), t[id].son.end(), cmp);
    }
    dfs(0, 0);
    return 0;
}
