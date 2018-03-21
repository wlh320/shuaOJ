#include <cstdio>
#include <vector>
using namespace std;
vector<int> g[1004];
vector<int> indegree;
int main()
{
    int nv, ne;
    scanf("%d %d", &nv, &ne);
    indegree.resize(nv + 1);
    for (int i = 0; i < ne; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        indegree[b]++;
    }
    int k;
    scanf("%d", &k);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        vector<int> tmpIn(indegree.begin(), indegree.end());
        vector<int> per(nv);
        for (int j = 0; j < nv; ++j) {
            scanf("%d", &per[j]);
        }
        for (int j = 0; j < nv; ++j) {
            int v = per[j];
            if (tmpIn[v] != 0) {
                ans.push_back(i);
                break;
            }
            for (auto it = g[v].begin(); it != g[v].end(); it++) {
                tmpIn[*it]--;
            }
        }
    }
    for (unsigned int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
