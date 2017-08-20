#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct App
{
    int no, ge, gi, g, rk;
    int app[5];
};
struct Scl
{
    int quota;
    int minrk;
    vector<int> stu;
};
App a[40000];
Scl s[100];

bool cmp(App &a, App &b) {
    if (a.g != b.g) {
        return a.g > b.g;
    } else {
        return a.ge > b.ge;
    }
}

int main()
{
    int n, m, k;//n-stud m-school k-apply
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &s[i].quota);
    }
    for(int i = 0; i < n; ++i) {
        a[i].no = i;
        scanf("%d %d", &a[i].ge, &a[i].gi);
        a[i].g = a[i].ge + a[i].gi;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &a[i].app[j]);
        }
    }
    sort(a, a+n, cmp);
    a[0].rk = 1;
    for(int i = 1; i < n; ++i) {
        if (a[i].g == a[i-1].g && a[i].ge == a[i-1].ge) {
            a[i].rk = a[i-1].rk;
        } else {
            a[i].rk = a[i-1].rk+1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            int sl = a[i].app[j];
            if (s[sl].quota > 0 || a[i].rk == s[sl].minrk) {
                s[sl].quota--;
                s[sl].minrk = a[i].rk;
                s[sl].stu.push_back(a[i].no);
                break;
            }
        }
    }
    for(int i = 0; i < m; ++i) {
        sort(s[i].stu.begin(), s[i].stu.end());
        for(int j = 0; j < s[i].stu.size(); ++j) {
            if (j != 0) printf(" ");
            printf("%d", s[i].stu[j]);
        }
        printf("\n");
    }
    return 0;
}
