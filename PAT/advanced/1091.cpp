// BFS求三维空间里的超过一定大小的连通块的个数
#include <cstdio>
#include <queue>
using namespace std;
const int dx[6] = {1, 0, 0, -1,  0,  0};
const int dy[6] = {0, 1, 0,  0, -1,  0};
const int dz[6] = {0, 0, 1,  0,  0, -1}; 
int g[1500][130][70];
bool visit[1500][130][70];
int m, n, l, t;
inline bool isValid(int x, int y, int z)
{
    return (x >= 0 && x < m && y >= 0 && 
        y < n && z >= 0 && z < l && 
        !visit[x][y][z] && g[x][y][z] == 1);
}
int bfs(int x, int y, int z)
{
    int cnt = 0;
    queue<int> q;
    if (isValid(x, y, z)) {
        visit[x][y][z] = true;
        q.push(x); q.push(y); q.push(z);
    }
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int z = q.front(); q.pop();
        cnt++;
        for(int i = 0; i < 6; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            int tz = z + dz[i];    
            if (isValid(tx, ty, tz)) {
                visit[tx][ty][tz] = true;
                q.push(tx); q.push(ty); q.push(tz);
            }
        }
    }
    if (cnt < t) cnt = 0; // cnt no less than t
    return cnt;
}
int main()
{
    int cnt = 0;
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int k = 0; k < l; ++k) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &g[i][j][k]);
            }
        }
    }
    for(int k = 0; k < l; ++k) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cnt += bfs(i, j, k);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
