// 对多个点用 Dijkstra 最短路
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
struct Node
{
    int v, l;
    Node(int v, int l) : v(v), l(l) {}
    bool operator < (const Node &b) const {
        return l > b.l;
    }
};
vector<Node> g[1024];
int dis[1024];
bool vis[1024];
int maxID = INF, maxDis = -1, sumDis = INF;
bool bigger(int id, int mind, int avgd) 
{
    if (mind != maxDis) {
        return mind > maxDis;
    } else {
        if (avgd != sumDis) {
            return avgd < sumDis;
        } else {
            return id < maxID;
        }
    }
}
void dijkstra(int src, int nH, int radius)
{
    for(int i = 0; i < 1024; ++i) {
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
            int len = g[v][i].l;
            if (!vis[v2] && dis[v2] > dis[v] + len) {
                dis[v2] = dis[v] + len;
                q.push(Node(v2, dis[v2]));
            }
        }
    }
    int dmin = INF, dsum = 0;
    for(int i = 1; i <= nH; ++i) { // find min distance
        dsum += dis[i];
        if (dis[i] > radius) { // invalid, return
            return ;
        }
        dmin = min(dmin, dis[i]);
    }
    if (bigger(src, dmin, dsum)) { // update gas station
        maxID = src;
        maxDis = dmin;
        sumDis = dsum;
    }
}

int main()
{
    int nH, nG, nArc, nVex, radius;
    scanf("%d %d %d %d", &nH, &nG, &nArc, &radius);
    char fs[8], ts[8];
    int from, to, w;
    for(int _ = 0; _ < nArc; ++_) {
        scanf("%s %s %d", fs, ts, &w);
        from = fs[0] == 'G' ? atoi(fs+1)+nH : atoi(fs);
        to = ts[0] == 'G' ? atoi(ts+1)+nH : atoi(ts); 
        g[from].push_back(Node(to, w));
        g[to].push_back(Node(from, w));
    }
    for(int i = nH+1; i <= nH+nG; ++i) {
        dijkstra(i, nH, radius);
    }
    if (maxID != INF) {
        printf("G%d\n", maxID-nH);
        printf("%d.0 %.1lf\n", maxDis, (double(sumDis)+0.05)/nH);
    } else {
        printf("No Solution\n");
    }
    return 0;
}
