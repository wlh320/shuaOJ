// 模拟停车场, 查询某时刻停车数量, 注意读题
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct Log
{
    char id[8];
    int time;
    bool in;
};
Log l[10000];
int qry[80000];
int hms2s(int h, int m, int s)
{
    return h*3600+m*60+s;
}
bool cmp1(const Log &a, const Log &b)
{
    if (strcmp(a.id, b.id) != 0) {
        return strcmp(a.id, b.id) < 0;
    } else {
        return a.time < b.time;
    }
}
bool cmp2(const Log &a, const Log &b)
{
    return a.time < b.time;
}
int main()
{
    int n, nQ;
    scanf("%d %d", &n, &nQ);
    int h, m, s;
    char act[4];
    for(int i = 0; i < n; ++i) { // input
        scanf("%s %d:%d:%d %s", l[i].id, &h, &m, &s, act);
        l[i].time = hms2s(h, m, s);
        if (!strcmp(act, "in")) {
            l[i].in = true;
        }
    }
    sort(l, l+n, cmp1); // sort by name
    vector<Log> valid;
    map<string, int> cntT; // each car's time
    int maxT = 0;
    for(int i = 0; i < n-1; ++i) { // erase invalid data
        if (!strcmp(l[i].id, l[i+1].id) && l[i].in && !l[i+1].in) {
            valid.push_back(l[i]);
            valid.push_back(l[i+1]);
            cntT[l[i].id] += (l[i+1].time - l[i].time);
            maxT = max(maxT, cntT[l[i].id]);
        }
    }
    n = valid.size();
    sort(valid.begin(), valid.end(), cmp2); // sort by time
    int cntCar = 0, t = 0, tmp;
    for(int i = 0; i < nQ; ++i) {
        scanf("%d:%d:%d", &h, &m, &s);
        tmp = hms2s(h, m, s);
        for(; valid[t].time <= tmp && t < n; ++t) { // 不用从头找
            if (valid[t].in) { cntCar++; } // car in
            else { cntCar--; } // car out
        }
        printf("%d\n", cntCar);
    }
    map<string, int>::iterator it;
    for(it = cntT.begin(); it != cntT.end(); ++it) {
        if (it->second == maxT) {
            printf("%s ", it->first.c_str());
        }
    }
    h = maxT / 3600; m = maxT % 3600 / 60; s = maxT % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}
