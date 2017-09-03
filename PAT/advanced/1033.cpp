// 贪心~ 关键是弄清楚各种情况
#include <cstdio>
#include <algorithm>
using namespace std;
struct Station
{
    double d; // distance
    double p; // price
};
Station s[512];
const int INF = 99999999;
bool cmp(Station &a, Station &b) { return a.d < b.d; }
int main()
{
    int n;
    double cmax, dis, avg;
    scanf("%lf %lf %lf %d", &cmax, &dis, &avg, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lf %lf", &s[i].p, &s[i].d);
    }
    s[n].p = 0; s[n].d = dis;
    sort(s, s+n+1, cmp); // sort by distance
    if (s[0].d != 0) { // tank is empty at beginning
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    double goMax = avg * cmax;
    double curDis = 0, cost = 0, left = 0;
    double curPrice = s[0].p;
    while(curDis < dis) { // while not get to destination
        double searchDis = curDis + goMax;
        double minP = INF, minDis = 0;
        bool flag = false;
        for(int i = 0; i < n+1 && s[i].d <= searchDis; ++i) {
            if (s[i].d <= curDis) continue;
            if (s[i].p < curPrice) { // find station cheaper
                cost += (s[i].d - left - curDis) * curPrice / avg;
                left = 0;
                curPrice = s[i].p; curDis = s[i].d;
                flag = true;
                break;
            }
            if (s[i].p < minP) { // choose the cheapest station
                minP = s[i].p;
                minDis = s[i].d;
            }
        }
        if (!flag && minP != INF) {
            cost += curPrice * (cmax - left / avg); // fill tank full
            left = goMax - (minDis - curDis); // gas left
            curPrice = minP;
            curDis = minDis;

        } else if (!flag && minP == INF) { // can't get to next station
            curDis += goMax;
            printf("The maximum travel distance = %.2lf\n", curDis);
            return 0;
        }
    }
    printf("%.2lf\n", cost);
    return 0;
}
