// DFS求树所有叶子节点的层数并计算
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
struct Node
{
    int n;
    vector<int> son;
    int amt; // 货的量
};
Node t[100000];
double sum = 0;
double p, r;
void dfs(int root, int lvl)
{
    if (!t[root].n) {
        sum += t[root].amt*p*pow((1.0+r/100.0), lvl);
    }
    for(int i = 0; i < t[root].n; ++i) {
        dfs(t[root].son[i], lvl+1);
    }
}
int main()
{
    int n, k, tmp;
    scanf("%d", &n);
    scanf("%lf %lf", &p, &r);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &k);
        t[i].n = k;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &tmp);
            t[i].son.push_back(tmp);
        }
        if (k == 0) {
            scanf("%d", &t[i].amt);
        }
    }
    dfs(0, 0); // root=0
    printf("%.1lf\n", sum);
    return 0;
}
