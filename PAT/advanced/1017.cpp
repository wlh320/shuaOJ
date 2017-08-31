// 排队服务, 用一个优先队列用于取得离到来时间最近的队伍
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
#define TIME_S 8*60*60
#define TIME_E 17*60*60
inline int hms2s(int h, int m, int s)
{
    return 60*60*h+60*m+s;
}
struct Cus
{
    int s; // arrive seconds
    int t; // serve time
};
Cus c[10000];
bool cmp(Cus a, Cus b)
{
    return a.s < b.s;
}
int main()
{
    int n, nq;
    int h, m, s, t;
    priority_queue<int, vector<int>, greater<int> > q; // 记录每个队伍的最后时间
    scanf("%d %d", &n, &nq);

    for(int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d", &h, &m, &s, &t);
        c[i].s = hms2s(h, m, s);
        t = std::min(t, 60);
        c[i].t = t;
    }
    std::sort(c, c+n, cmp); // 按来到时间排序

    int wait = 0; // 总等待时间
    int servN = 0;
    for(int i = 0; i < nq; ++i) {q.push(TIME_S);}
    for(int i = 0; i < n; ++i) {
        if (c[i].s > TIME_E) continue;
        int lastTime = q.top();
        if (lastTime  > c[i].s) {
            wait += (lastTime - c[i].s);
            q.push(lastTime+c[i].t*60); // 等待后更新队伍的可服务时间
        } else {
            q.push(c[i].s+c[i].t*60); // 无需等待
        }
        q.pop();
        servN++;
    }
    printf("%.1lf\n", double(wait) / 60.0 / servN);
    return 0;
}
