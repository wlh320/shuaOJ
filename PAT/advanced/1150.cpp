#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
int nVex, nArc;
int min_dist = INT_MAX;
int min_i = 0;
int g[256][256];

void cal(int no, const vector<int> &path)
{
    printf("Path %d:", no);
    bool vis[256] = { false };
    bool isSimple = true;
    int dist = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int src = path[i];
        int dst = path[i + 1];
        if (g[src][dst] == 0) {
            printf(" NA (Not a TS cycle)\n");
            return ;
        }
        if (vis[src]) {
            isSimple = false;
        }
        vis[src] = true;
        dist += g[src][dst];
    }
    int sum = 0;
    for (int i = 1; i <= nVex; i++) {
        if (vis[i]) sum++;
    }
    if (sum == nVex && isSimple && path[0] == path.back()) {
        printf(" %d (TS simple cycle)\n", dist);
        if (dist < min_dist) {
            min_dist = dist;
            min_i = no;
        }
    } else if (sum == nVex && !isSimple && path[0] == path.back()) {
        printf(" %d (TS cycle)\n", dist);
        if (dist < min_dist) {
            min_dist = dist;
            min_i = no;
        }
    } else {
        printf(" %d (Not a TS cycle)\n", dist);
    }
}

int main()
{
    scanf("%d %d", &nVex, &nArc);
    for (int i = 0; i < nArc; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        g[x][y] = w;
        g[y][x] = w;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int len;
        scanf("%d", &len);
        vector<int> path(len);
        for (int j = 0; j < len; j++) {
            scanf("%d", &path[j]);
        }
        cal(i, path);
    }
    printf("Shortest Dist(%d) = %d\n", min_i, min_dist);
    return 0;
}
