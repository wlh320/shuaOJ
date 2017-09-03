// 又一个排队问题,这次要考虑特殊情况-VIP
// 真尼玛复杂啊 我太菜了参考了网上的一些博客 才理顺了
// 说好的不会九点之后到呢???
#include <cstdio>
#include <queue>
#include <algorithm>
#define TIME_START 8*60*60
#define TIME_END 21*60*60
const int INF = 0x3f3f3f3f;
using namespace std;
struct Pair
{
    int arrv; // arrive time
    int start; // start time
    int serv; // serve time
    int wait;
    int vip; // 1-vip 0-no
    Pair() : start(INF) {}
};
struct Tbl
{
    int last; // last avaiable time
    bool vip; // is vip table
    int cnt; // number of pairs it serves
    Tbl(): last(TIME_START), vip(false) {}
};
int hms2s(int h, int m, int s)
{
    return h*60*60+m*60+s;
}
bool cmp(Pair a, Pair b) { return a.arrv < b.arrv; }
bool cmp2(Pair a, Pair b) 
{ 
    if (a.start != b.start) {
        return a.start < b.start;
    } else {
        return a.arrv < b.arrv;
    }
}
Pair p[10005];
Tbl t[201];
void printTime(int t)
{
    int h, m, s;
    h = t / 3600; m = (t % 3600) / 60; s = t % 60;
    printf("%02d:%02d:%02d", h, m, s);
}
void play(int pid, int tid)
{
    p[pid].start = max(p[pid].arrv, t[tid].last);
    p[pid].wait = p[pid].start - p[pid].arrv;
    t[tid].last = p[pid].start + p[pid].serv;
    if (p[pid].start < TIME_END)
        t[tid].cnt++;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int h, m, s, t;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &t, &p[i].vip);
        p[i].arrv = hms2s(h, m, s);
        t = min(t, 120);
        p[i].serv = t*60;
    }
    sort(p, p+n, cmp); // sort by arrive time
    int nT, nVT; // table / vip table
    scanf("%d %d", &nT, &nVT);
    for(int i = 0; i < nVT; ++i) {
        int no;
        scanf("%d", &no);
        t[no-1].vip = true;
    }

    for(int i = 0; i < n; ++i) {
        if (p[i].start != INF) continue;
        int lastTbl = INF;
        for(int j = 0; j < nT; ++j) {
            lastTbl = min(lastTbl, t[j].last);
        }
        int fstServT = max(lastTbl, p[i].arrv);
        if (fstServT >= TIME_END) break;
        vector<int> candiPair; // candidate pairs
        vector<int> candiTbl; // candidate tables
        for(int j = i; j < n; ++j)
            if(p[j].start == INF && p[j].arrv <= fstServT) candiPair.push_back(j);
        for(int j = 0; j < nT; ++j)
            if(t[j].last <= fstServT) candiTbl.push_back(j);
        bool isServed = false;
        if (candiPair.size() == 1 && candiTbl.size() > 1) {
            if (p[candiPair[0]].vip) { // vip first
                for(int j = 0; j < candiTbl.size(); ++j) {
                    if (t[candiTbl[j]].vip) {
                        play(candiPair[0], candiTbl[j]);
                        isServed = true;
                        break;
                    }
                }
            }
        } else if (candiPair.size() > 1 && candiTbl.size() >= 1) {
            for(int ti = 0; ti < candiTbl.size(); ++ti) {
                if(t[candiTbl[ti]].vip) {
                    for(int pi = 0; pi < candiPair.size(); ++pi) {
                        if (p[candiPair[pi]].vip) {
                            play(candiPair[pi], candiTbl[ti]);
                            isServed = true;
                            break;
                        }
                    }
                }
            }
        }
        if(!isServed) {
            play(candiPair[0], candiTbl[0]);
        }
        --i;
    }
    sort(p, p+n, cmp2);
    int h, m, s;
    for(int i = 0; i < n; ++i) {
        if (p[i].start >= TIME_END) break;
        printTime(p[i].arrv);
        printf(" ");
        printTime(p[i].start);
        printf(" %d\n", (p[i].wait+30)/60); // 四舍五入
    }
    for(int i = 0; i < nT; ++i) {
        printf("%d", t[i].cnt);
        if (i != nT-1) printf(" ");
        else printf("\n");
    }
    return 0;
}
