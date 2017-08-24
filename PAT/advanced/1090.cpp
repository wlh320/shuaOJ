// DFS求树最大的深度及节点个数
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
int maxl = 0;
int nMax = 0;
void dfs(int root, int lvl)
{
    if (!t[root].n) {
        if(lvl > maxl) {
            maxl = lvl;
            nMax = 1;
        } else if (lvl == maxl) {
            nMax++;
        }
    }
    for(int i = 0; i < t[root].n; ++i) {
        dfs(t[root].son[i], lvl+1);
    }
}
int main()
{
    int n, tmp, root;
    double p, r;
    scanf("%d", &n);
    scanf("%lf %lf", &p, &r);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        if (tmp != -1) {
            t[tmp].n++;
            t[tmp].son.push_back(i);
        } else {
            root = i;
        }
    }
    dfs(root, 0);
    double res = p*pow((1.0+r/100.0), maxl); 
    printf("%.2lf %d\n", res, nMax);
    return 0;
}
