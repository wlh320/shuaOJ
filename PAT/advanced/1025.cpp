#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct Stud
{
    char no[14];
    int score;
    int loc;
    int locRank;
};
bool cmp(Stud a, Stud b)
{
    if (a.score != b.score) {
        return a.score >= b.score;
    } else {
        return strcmp(a.no, b.no) < 0;
    }
    
}
Stud loc[300];
Stud all[30000];
int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; ++j) {
            scanf("%s %d", loc[j].no, &loc[j].score);
            loc[j].loc = i;
        }
        sort(loc, loc+k, cmp);
        for(int j = 0; j < k; ++j) {
            loc[j].locRank = j + 1;
            if (j != 0 && loc[j].score == loc[j-1].score) {
                loc[j].locRank = loc[j-1].locRank;
            }
            strcpy(all[cnt].no, loc[j].no);
            all[cnt].loc = loc[j].loc;
            all[cnt].locRank = loc[j].locRank;
            all[cnt].score = loc[j].score;
            cnt++;
        }
    }
    sort(all, all+cnt, cmp);
    printf("%d\n", cnt);
    int frank = 1;
    int pre = 1;
    for(int i = 0; i < cnt; ++i) {
        frank = (i!=0 && all[i].score == all[i-1].score)?pre:i+1;
        printf("%s %d %d %d\n", all[i].no, frank, all[i].loc, all[i].locRank);
        pre = frank;
    }
    return 0;
}
