// DFS求树最小的深度及节点个数
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
struct Node
{
    int n;
    vector<int> son;
};
Node t[100000];
int minl = 999999;
int nMin = 0;
void dfs(int root, int lvl)
{
    if (!t[root].n) {
        if(lvl < minl) {
            minl = lvl;
            nMin = 1;
        } else if (lvl == minl) {
            nMin++;
        }
    }
    for(int i = 0; i < t[root].n; ++i) {
        dfs(t[root].son[i], lvl+1);
    }
}
int main()
{
    int n, k, tmp;
    double p, r;
    scanf("%d", &n);
    scanf("%lf %lf", &p, &r);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &k);
        t[i].n = k;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &tmp);
            t[i].son.push_back(tmp);
        }
    }
    dfs(0, 0); // root=0
    double res = p*pow((1.0+r/100.0), minl); 
    printf("%.4lf %d", res, nMin);
    return 0;
}
