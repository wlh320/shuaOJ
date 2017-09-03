// 双权值的 Dijkstra 最短路 (用了堆优化的模板)
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
bool isT = false; // 为了两次查找堆使用不同的关键字
struct Node
{
    int v, d, t; // vertex distance time 
    Node(int v=-1,int d=0,int t=0) :v(v),d(d),t(t){}
    bool operator < (const Node &b) const {
        if (isT) {
            return t > b.t;
        } else {
            return d > b.d;
        }
    }
};
vector<Node> g[512];
int src, dst;
bool visit[512];
int dis[512];
int tim[512];
int len[512]; // 为了找最快且经过点最少
int ansD[512];
int ansT[512];

void dijkstra(bool isTime) // 堆优化的Dijkstra
{
    for(int i = 0; i < 500; ++i) { 
        dis[i] = INF; 
        tim[i] = isTime ? INF : 0;
        len[i] = 0;
        visit[i] = false;
    }
    priority_queue<Node> q;
    q.push(Node(src,0,0));
    dis[src] = 0;
    tim[src] = 0;
    len[src] = 0;
    while(!q.empty()) {
        Node now = q.top(); q.pop();
        int v = now.v;
        if (visit[v]) continue;
        visit[v] = true;
        for(int i = 0; i < g[v].size(); ++i) {
            int v2 = g[v][i].v;
            int d = g[v][i].d;
            int t = g[v][i].t;
            if (!isTime) { // 按照距离找最短
                if (!visit[v2]) {
                    if (dis[v2] > dis[v] + d || 
                    (dis[v2] == dis[v]+ d && tim[v2] > tim[v] + t)) {
                        dis[v2] = dis[v] + d;
                        tim[v2] = tim[v] + t;
                        ansD[v2] = v;
                        q.push(Node(v2, dis[v2], tim[v2]));
                    }
                }
            } else { // 按照时间找最短
                if (!visit[v2]) {
                    if (tim[v2] > tim[v] + t || 
                    (tim[v2] == tim[v]+ t && len[v2] > len[v] + 1)) {
                        tim[v2] = tim[v] + t;
                        len[v2] = len[v] + 1;
                        ansT[v2] = v;
                        q.push(Node(v2, dis[v2], tim[v2]));
                    }
                }
            }
        }
    }
}

vector<int> getPath(int dest, int pre[]) 
{
    vector<int> ans;
    while(dest != -1) {
        ans.push_back(dest);
        dest = pre[dest];
    }
    return ans;
}

void printPath(vector<int> ans) 
{
    vector<int>::reverse_iterator it;
    for(it = ans.rbegin(); it != ans.rend(); ++it) {
        if (it != ans.rbegin()) printf(" -> ");
        printf("%d", *it);
    }
    printf("\n");
}

int main()
{
    int nVex, nArc;
    scanf("%d %d", &nVex, &nArc);
    int from, to, one, d, t;
    for(int i = 0; i < nVex; ++i) {
        ansT[i] = -1;
        ansD[i] = -1;
    }
    for(int i = 0; i < nArc; ++i) {
        scanf("%d %d %d %d %d", &from, &to, &one, &d, &t);
        g[from].push_back(Node(to, d, t));
        if (!one) {
            g[to].push_back(Node(from, d, t));
        }
    }
    scanf("%d %d", &src, &dst);
    dijkstra(isT); // 求距离最短的路径, 距离相等找时间最少
    vector<int> ans1 = getPath(dst, ansD);
    int mindis = dis[dst];
    isT = true;
    dijkstra(isT); // 求时间最短的路径, 时间相等找路径长度最小
    vector<int> ans2 = getPath(dst, ansT);
    int mintim = tim[dst];
    if (ans1 == ans2) { // 两次路径相等
        printf("Distance = %d; Time = %d: ", mindis, mintim);
        printPath(ans1);
    } else {
        printf("Distance = %d: ", mindis);
        printPath(ans1);
        printf("Time = %d: ", mintim);
        printPath(ans2);
    }
    return 0;
}
