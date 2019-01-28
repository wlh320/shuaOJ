#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
struct Edge {
    int src, dst;
    Edge(int src, int dst)
        : src(src)
        , dst(dst)
    {
    }
};
int n, m;
vector<Edge> edges;
int check()
{
    set<int> s;
    map<int, int> colors;
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        colors[i] = c;
        s.insert(c);
    }
    for (unsigned int i = 0; i < edges.size(); i++) {
        int src = edges[i].src;
        int dst = edges[i].dst;
        if (colors[src] == colors[dst]) {
            return -1;
        }
    }
    return s.size();
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        edges.push_back(Edge(s, t));
    }
    int tmp;
    scanf("%d", &tmp);
    while (tmp--) {
        int ans = check();
        if (ans == -1) {
            printf("No\n");
        } else {
            printf("%d-coloring\n", ans);
        }
    }
    return 0;
}