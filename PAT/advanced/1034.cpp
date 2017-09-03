// 并查集得到所有帮派,确定头目, 最后判断帮派是否符合标准
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct Gang
{
    int head;
    int size;
    Gang(int h=0) : head(h), size(0) {}
};
int u[2048];
map<string, int> n2id;
string name[2048];
int score[2048];
int cnt = 0;
int nGang = 0;
bool cmp(Gang a, Gang b) { return name[a.head] < name[b.head]; }
int find(int x)
{
    int pre = x;
    while(u[pre] != pre) { pre = u[pre]; }
    int p = x, q;
    while(p != pre) {
        q = u[p];
        u[p] = pre;
        p = q;
    }
    return pre;
}
void join(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y) {
        u[x] = y;
    }
}
int mapName(const char *s)
{
    if (n2id.find(s) == n2id.end()) { // not found
        n2id[s] = cnt;
        name[cnt++] = s;
    }
    return n2id[s];
}
int main()
{
    for(int i = 0; i < 2048; ++i) u[i] = i;
    int n, thre, w;
    scanf("%d %d", &n, &thre);
    char fs[4], ts[4];
    for(int i = 1; i <= n; ++i) {
        scanf("%s %s %d", fs, ts, &w);
        int from = mapName(fs);
        int to = mapName(ts);
        score[from] += w; score[to] += w;
        join(from, to);
    }
    vector<int> pres; // union find fathers
    vector<Gang> g;
    for(int i = 0; i < cnt; ++i) {
        int pre = u[i];
        if (pre != i) {
            pre = u[i] = find(i);
        } else {
            pres.push_back(i);
            nGang++;
        }
    }
    for(int i = 0; i < nGang; ++i) {
        Gang gg(pres[i]);
        int pre = pres[i], head = pre, total = 0;
        for(int j = 0; j < cnt; ++j) {
            if (u[j] == pre) {
                gg.size++;
                total += score[j];
                if (score[j] > score[head]) {
                    head = j;
                }
            }
        }
        if (gg.size > 2 && total > thre*2) {
            gg.head = head;
            g.push_back(gg);
        }
    }
    printf("%ld\n", g.size());
    sort(g.begin(), g.end(), cmp);
    for(int i = 0; i < g.size(); ++i) {
        printf("%s %d\n", name[g[i].head].c_str(), g[i].size);
    }
    return 0;
}
