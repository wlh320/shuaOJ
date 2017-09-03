// 算每月电话账单, 挺麻烦的一个模拟
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
struct Log
{
    char name[24];
    int mon, day, hor, min, sum;
    bool on;
};
struct Data // 每条数据
{
    int sd, sh, sm;
    int ed, eh, em;
    int diff; // endDate - startDate
    double mnt;
    Data(const Log &a, const Log &b): sd(a.day), sh(a.hor), sm(a.min),
    ed(b.day), eh(b.hor), em(b.min), mnt(0) {}
};
bool cmp(Log &a, Log &b)
{
    if (strcmp(a.name, b.name)) {
        return strcmp(a.name, b.name) < 0;
    } else {
        return a.sum < b.sum;
    }
}
int pph[24]; // price per hour
int allday;
Log l[1000];
typedef map<int, vector<Data> > Bill;
map<string, Bill> m;
double mntFromZero(int h, int m)
{
    double sum = 0;
    for(int i = 0; i < h; ++i) {
        sum += pph[i]*60;
    }
    sum += m*pph[h];
    return sum;
}
double cntMoney(const Data &d)
{
    double sum = 0;
    sum += (d.ed - d.sd)* 60 * allday; // full day
    sum += mntFromZero(d.eh, d.em) - mntFromZero(d.sh, d.sm);
    return sum/100;
}
int main()
{
    for(int i = 0; i < 24; ++i) { // input price
        scanf("%d", &pph[i]);
        allday += pph[i];
    }
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) { // input call log
        char tmp[10];
        scanf("%s %d:%d:%d:%d %s", l[i].name, &l[i].mon, &l[i].day, 
        &l[i].hor, &l[i].min, tmp);
        if (!strcmp(tmp, "on-line")) l[i].on = true;
        l[i].sum = l[i].mon*30*24*60+l[i].day*24*60+l[i].hor*60+l[i].min;
    }
    sort(l, l+n, cmp);
    for(int i = 1; i < n; ++i) { // select valid calls
        if (!strcmp(l[i-1].name, l[i].name) && l[i-1].on && !l[i].on) {
            Data d(l[i-1], l[i]);
            d.diff = l[i].sum - l[i-1].sum;
            d.mnt = cntMoney(d);
            m[l[i].name][l[i-1].mon].push_back(d);
        }
    }
    map<string, Bill>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
        printf("%s", it->first.c_str()); // name
        Bill b = it->second; Bill::iterator bit;
        for(bit = b.begin(); bit != b.end(); ++bit) {
            printf(" %02d\n", bit->first); // month
            vector<Data> v = bit->second;
            double sum = 0;
            for(int i = 0; i < v.size(); ++i) { // call
                printf("%02d:%02d:%02d", v[i].sd, v[i].sh, v[i].sm);
                printf(" %02d:%02d:%02d %d", v[i].ed, v[i].eh, v[i].em, v[i].diff);
                printf(" $%.2lf\n", v[i].mnt);
                sum += v[i].mnt;
            }
            printf("Total amount: $%.2lf\n", sum);
        }
    } 
    return 0;
}
