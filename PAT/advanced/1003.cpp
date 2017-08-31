#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int src, dest;
int wVex[512];
int wArc[512][512];
vector<int> arc[512];
bool visit[512];
map<int, int> cnt;
map<int, int> maxW;
void dfs(int vex, int dis, int w)
{
    if (vex == dest) {
        cnt[dis]++;
        maxW[dis] = max(maxW[dis], w);
        return ; // 搜到解回溯
    }
    visit[vex] = true; // 防止再走回来
    for(int i = 0; i < arc[vex].size(); ++i) {
        int to = arc[vex][i];
        if (!visit[to]) {
            dfs(to, dis+wArc[vex][to], w+wVex[to]);
        }
    }
    visit[vex] = false;
}
int main()
{
    int nVex, nArc;
    scanf("%d %d %d %d", &nVex, &nArc, &src, &dest);
    for(int i = 0; i < nVex; ++i) {
        scanf("%d", &wVex[i]);
    }
    for(int i = 0; i < nArc; ++i) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        arc[start].push_back(end);
        arc[end].push_back(start);
        wArc[start][end] = weight;
        wArc[end][start] = weight;
    }
    dfs(src, 0, wVex[src]);
    map<int, int>::iterator it = cnt.begin();
    printf("%d ", it->second);
    it = maxW.begin();
    printf("%d\n", it->second);
    return 0;
}
