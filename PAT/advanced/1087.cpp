// 求最短路径的条数和途径点的权值之和
// 求的东西比较多, DFS写的比较烦, 其实还不如写最短路
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;
int src, dst;
vector<string> name;
int path[200];
vector<int> g[200];
int wArc[200][200];
int wVex[200];
bool visit[200];
map<string, int> ct2id; // city name -> id
map<int, int> cnt; // count every path
map<int, int> cntHap;
map<int, int> cntDep;
map<int, vector<int> > ans;
void dfs(int v, int len, int hap, int depth)
{
    path[depth] = v; // 记录经过的路径
    if (v == dst) { // arrive Rome
        cnt[len]++;
        int maxHap = cntHap[len];
        int maxDepth = cntDep[len];
        if (maxDepth == 0) {
            maxDepth = 0x3f3f3f3f;
        }
        if (hap > maxHap || (hap == maxHap && depth < maxDepth)) {
            cntHap[len] = hap;
            cntDep[len] = depth;
            ans[len].assign(path, path+depth+1);
        }
        return ;
    }
    visit[v] = true;
    for(int i = 0; i < g[v].size(); ++i) {
        int v2 = g[v][i];
        if (!visit[v2]) {
            dfs(v2, len+wArc[v][v2], hap+wVex[v2], depth+1);
        }
    }
    visit[v] = false;
}

int main()
{
    int nVex, nArc;
    char tmp[4];
    scanf("%d %d %s", &nVex, &nArc, tmp);
    ct2id[tmp] = 0;
    name.push_back(tmp);
    for(int i = 1; i < nVex; ++i) {
        scanf("%s %d", tmp, &wVex[i]);
        ct2id[tmp] = i;
        name.push_back(tmp);
    }
    char fs[4], ts[4];
    int from, to, w;
    for(int i = 0; i < nArc; ++i) {
        scanf("%s %s %d", fs, ts, &w);
        from = ct2id[fs]; to = ct2id[ts];
        wArc[from][to] = wArc[to][from] = w;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    src = 0; dst = ct2id["ROM"];
    dfs(src, 0, 0, 0);
    int dis = cnt.begin()->first;
    int disCnt = cnt.begin()->second;
    int maxHap = cntHap[dis];
    int avgHap = maxHap / cntDep[dis];
    printf("%d %d ", disCnt, dis);
    printf("%d %d\n", maxHap, avgHap);
    for(int i = 0; i < ans[dis].size(); ++i) {
        if (i != 0) printf("->");
        printf("%s", name[ans[dis][i]].c_str());
    }
    return 0;
}
