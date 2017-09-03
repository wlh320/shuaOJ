// DFS 遍历所有地铁路线取出合适的
#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 10001
#define INF 0x3f3f3f3f
int tran[MAXN][MAXN];
vector<int> g[MAXN];
bool vis[MAXN];
int src, dst;
vector<int> tpath;
vector<int> path;
int minDep = INF; // 最小站数
int minTrans = INF; // 最少换乘
int cntTrans(vector<int> p)
{
    int ans = 0, curLine = 0;
    for(int i = 1; i < p.size(); ++i) {
        int from = p[i-1], to = p[i];
        if (tran[from][to] != curLine) {
            curLine = tran[from][to];
            ans++;
        }
    }
    return ans;
}
void printPath()
{
    printf("%d\n", minDep);
    int pre = path[0], curLine = 0;
    for(int i = 1; i < path.size(); ++i) {
        int from = path[i-1], to = path[i];
        if (tran[from][to] != curLine) {
            if(curLine != 0) printf("Take Line#%d from %04d to %04d.\n", curLine, pre, from);
            curLine = tran[from][to];
            pre = from;
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", curLine, pre, path[path.size()-1]);
}

void dfs(int v, int depth) 
{
    if (v == dst) { // 到终点
        if (depth < minDep) {
            minDep = depth;
            minTrans = cntTrans(tpath);
            path = tpath;
        } else if (depth == minDep) {
            int trans = cntTrans(tpath);
            if (trans < minTrans) {
                minTrans = trans;
                path = tpath;
            }
        }
        return ;
    }
    for(int i = 0; i < g[v].size(); ++i) {
        int v2 = g[v][i];
        if (!vis[v2]) {
            vis[v2] = true;
            tpath.push_back(v2);
            dfs(v2, depth+1);
            tpath.pop_back();
            vis[v2] = false;
        }
    }
}

int main()
{
    int nline, lineno, pre;
    int ns, s;
    scanf("%d", &nline);
    for(int i = 1; i <= nline; ++i) {
        scanf("%d %d", &ns, &pre);
        tran[pre][pre] = i;
        for(int j = 0; j < ns-1; ++j) {
            scanf("%d", &s);
            tran[pre][s] = tran[s][pre] = tran[s][s] = i;
            g[pre].push_back(s); g[s].push_back(pre);
            pre = s;
        }
    }
    int nq;
    scanf("%d", &nq);
    while(nq--) {
        scanf("%d %d", &src, &dst);
        for(int i = 0; i < MAXN; ++i) vis[i] = false;
        minDep = INF; // 最小站数
        minTrans = INF; // 最少换乘
        vis[src] = true;
        tpath.clear(); tpath.push_back(src);
        dfs(src, 0);
        printPath();
    }
    return 0;
}
