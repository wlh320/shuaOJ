#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct DC
{
    int no;
    int de;
    int cai;
    int type;
};

bool cmp(DC &a, DC &b)
{
    bool flag1 = (a.type < b.type);
    bool flag2 = (a.type == b.type) && (a.de + a.cai) > (b.de + b.cai);
    bool flag3 = (a.type == b.type) && (a.de + a.cai) == (b.de + b.cai) && (a.de > b.de);
    bool flag4 = (a.type == b.type) && (a.de + a.cai) == (b.de + b.cai) && (a.de == b.de) && (a.no < b.no);
    return flag1 | flag2 | flag3 | flag4;
}

int main()
{
    int n,l,h;
    int m = 0;
    vector<DC> stu;
    scanf("%d %d %d", &n, &l, &h);
    for(int i = 0; i < n; ++i) {
        DC dc;
        scanf("%d %d %d", &dc.no, &dc.de, &dc.cai);
        if (dc.de >= l && dc.cai >= l) {
            if (dc.de >= h && dc.cai >= h) {
                dc.type = 1;
            } else if (dc.de >= h) {
                dc.type = 2;
            } else if (dc.de >= dc.cai) {
                dc.type = 3;
            } else {
                dc.type = 4;
            }
            stu.push_back(dc);
            m++;
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    printf("%d\n", m);
    for(int i = 0; i < m; ++i) {
        printf("%d %d %d\n", stu[i].no, stu[i].de, stu[i].cai);
    }
    return 0;
}
