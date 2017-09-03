// 多关键字 Dijstra 最短路径 + 最短路径打印
#include <cstdio>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f;
using namespace std;
struct Node
{
    int v, len, cost;
    Node(int v=0, int l=0, int c=0): v(v), len(l), cost(c) {}
    bool operator < (const Node &a) const {
        if (len == a.len) {
            return cost > a.cost;
        } else {
            return len > a.len;
        }
    }
};
vector<Node> g[512]; // graph
bool vis[512]; // visit
int dis[512]; // distance
int cost[512]; // cost
int pre[512]; // previous
void dij(int s) // 从s出发的dij
{
    priority_queue<Node> q;
    q.push(Node(s));
    dis[s] = 0;
    while(!q.empty()) {
        Node now = q.top(); q.pop();
        int v = now.v;
        if (vis[v]) continue;
        vis[v] = true;
        for(int i = 0; i < g[v].size(); ++i) {
            int v2 = g[v][i].v;
            int len = g[v][i].len;
            int cs = g[v][i].cost;
            if (!vis[v2]) {
                if (dis[v2] > dis[v] + len) {
                    dis[v2] = dis[v] + len;
                    cost[v2] = cost[v] + cs;
                    pre[v2] = v;
                    q.push(Node(v2, dis[v2], cost[v2]));
                } else if (dis[v2] == dis[v] + len && cost[v2] > cost[v] + cs) {
                    cost[v2] = cost[v] + cs;
                    pre[v2] = v;
                    q.push(Node(v2, dis[v2], cost[v2]));
                }
            }
        }
    }
}

void printPath(int dst)
{
    vector<int> ans;
    ans.push_back(dst);
    while(pre[dst] != -1) {
        dst = pre[dst];
        ans.push_back(dst);
    }
    for(int i = ans.size()-1; i >= 0; --i) {
        printf("%d ", ans[i]);
    }
}

int main()
{
    int nVex, nArc, src, dst;
    scanf("%d %d %d %d", &nVex, &nArc, &src, &dst);
    for(int i = 0; i < nVex; ++i) {
        vis[i] = false;
        dis[i] = INF;
        cost[i] = 0;
        pre[i] = -1;
    }
    for(int i = 0; i < nArc; ++i) {
        int from, to, len, cost;
        scanf("%d %d %d %d", &from, &to, &len, &cost);
        g[from].push_back(Node(to, len, cost));
        g[to].push_back(Node(from, len, cost));
    }
    dij(src);
    printPath(dst);
    printf("%d %d\n", dis[dst], cost[dst]);
    return 0;
}
