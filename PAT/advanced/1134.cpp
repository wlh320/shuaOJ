// 遍历所有边, 如找到某条边的顶点在集合里就计数, 看计数值是否为总边数
#include <cstdio>
#include <vector>
using namespace std;
struct Node
{
    int s, e;
    Node(int s, int e) :s(s), e(e) {}
};
vector<Node> g;
bool set[10001];
int main()
{
    int nVex, nArc;
    scanf("%d %d", &nVex, &nArc);
    for(int i = 0; i < nArc; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        g.push_back(Node(from, to));
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        vector<Node> tg(g);
        int n;
        scanf("%d", &n);
        for(int j = 0; j < nVex; ++j) // init
            set[j] = false;
        for(int j = 0; j < n; ++j) {
            int v;
            scanf("%d", &v);
            set[v] = true;
        }
        int sum = 0;
        for(int j = 0; j < tg.size(); ++j) {
            if (set[tg[j].s] || set[tg[j].e])
                sum++;
        }
        if (sum == nArc) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
