// Dijkstra 找出并存储所有最短路, 然后DFS从中找符合条件的
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define PBMC 0
struct Node
{
    int v, l;
    Node(int v, int l): v(v), l(l) {}
    bool operator < (const Node &b) const {
        return l > b.l;
    }
};
vector<Node> g[512];
bool vis[512];
int dis[512];
int bike[512];
vector<int> pre[512]; // 记录路径
void dijkstra(int nVex, int src)
{
    for(int i = 0; i < 512; ++i) {
        dis[i] = INF;
        vis[i] = false;
    }
    priority_queue<Node> q;
    q.push(Node(src, 0));
    dis[src] = 0;
    while(!q.empty()) {
        Node now = q.top(); q.pop();
        int v = now.v;
        if (vis[v]) continue;
        vis[v] = true;
        for(int i = 0; i < g[v].size(); ++i) {
            int v2 = g[v][i].v;
            int l = g[v][i].l;
            if (!vis[v2] && dis[v2] > dis[v] + l) {
                dis[v2] = dis[v] + l;
                q.push(Node(v2, dis[v2]));
                pre[v2].clear();
                pre[v2].push_back(v);
            } else if (!vis[v2] && dis[v2] == dis[v] + l) {
                pre[v2].push_back(v);
            }
        }
    }
}
vector<int> path;
vector<int> minPath;
int minSend = INF, minBack = INF;
int tgt;
void dfs(int dst) // dfs遍历每一条路径
{
    path.push_back(dst);
    if (dst == PBMC) { // 回溯到起点
        int send = 0, take = 0; // send-需要从总部带的 take-途中带走的
        vector<int>::reverse_iterator it = path.rbegin()+1;
        for(; it != path.rend(); ++it) {
            int s = *it;
            if (bike[s] > tgt) { // 富裕, 带走
                take += (bike[s]-tgt);
            } else if (bike[s] < tgt) { // 不够
                take -= (tgt-bike[s]); // 先从随身带的里扣
                if (take < 0) { // 不够扣,从总部带
                    send += (-take);
                    take = 0;
                }
            }
        }
        if (send < minSend || (send == minSend && take < minBack)) {
            minSend = send;
            minBack = take;
            minPath.assign(path.begin(), path.end());
        }
        return ;
    }
    for(int i = 0; i < pre[dst].size(); ++i) {
        dfs(pre[dst][i]);
        path.pop_back();
    }
}

int main()
{
    int cmax, nVex, nArc, dst;
    scanf("%d %d %d %d", &cmax, &nVex, &dst, &nArc);
    for(int i = 1; i <= nVex; ++i) {
        scanf("%d", &bike[i]);
    }
    nVex++; tgt = cmax / 2;
    for(int i = 0; i < nArc; ++i) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        g[from].push_back(Node(to, w));
        g[to].push_back(Node(from, w));
    }
    dijkstra(nVex, PBMC);
    dfs(dst);
    vector<int>::reverse_iterator it = minPath.rbegin();
    printf("%d ", minSend);
    for(; it != minPath.rend(); ++it) {
        if (it != minPath.rbegin()) printf("->");
        printf("%d", *it);
    }
    printf(" %d\n", minBack);
    return 0;
}
