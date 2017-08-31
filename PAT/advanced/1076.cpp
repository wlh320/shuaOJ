// 限制深度的BFS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
bool visit[1001];
vector<int> arc[1001];
void bfs(int s, int depth)
{
    int cnt = 0, lvl = 0;
    int sz, p;
    for(int i = 1; i <= 1000; ++i) visit[i] = false;
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while(!q.empty()) {
        sz = q.size();
        cnt += sz;
        if (lvl == depth) {
            printf("%d\n", cnt-1);
            return ;
        }
        while(sz--) {
            p = q.front();
            for(int i = 0; i < arc[p].size(); ++i) {
                if (!visit[arc[p][i]]) {
                    q.push(arc[p][i]);
                    visit[arc[p][i]] = true;
                }
            }
            q.pop();
        }
        lvl++;
    }
    printf("%d\n", cnt-1);
}
int main()
{
    int n, depth, k;
    scanf("%d %d", &n, &depth);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        while(k--) {
            int tmp;
            scanf("%d", &tmp);
            arc[tmp].push_back(i);            
        }
    }
    int q, v;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &v);
        bfs(v, depth);
    }
    return 0;
}
