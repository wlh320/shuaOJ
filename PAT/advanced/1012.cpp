#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct Stud
{
    int name;
    int score[4];
    int rank[4];
};

Stud s[2001];
map<int, int> exist;
int stype = 0;
bool cmp(Stud s1, Stud s2)
{
    return s1.score[stype] > s2.score[stype];
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &s[i].name, 
            &s[i].score[1], &s[i].score[2], &s[i].score[3]);
        s[i].score[0] = s[i].score[1]+s[i].score[2]+s[i].score[3];
    }

    for(stype = 0; stype < 4; ++stype) {
        sort(s, s+n, cmp);
        int rank = 1;
        for(int i = 0; i < n; ++i) {
            s[i].rank[stype] = rank++;
            if (i != 0 && s[i].score[stype] == s[i-1].score[stype])
                s[i].rank[stype] = s[i-1].rank[stype];
        }
    }

    for(int i = 0; i < n; ++i) {
        exist[s[i].name] = i;
    }
    
    const char t[4] = {'A','C', 'M', 'E'};
    for(int i = 0; i < m; ++i) {
        int query;
        scanf("%d", &query);
        if (exist.find(query) == exist.end()) { // not found
            printf("N/A\n");
        } else {
            int no = exist[query];            
            int minIdx = 0;
            for(int j = 1; j < 4; ++j) {
                minIdx = s[no].rank[j] < s[no].rank[minIdx] ? j : minIdx;
            }
            printf("%d %c\n", s[no].rank[minIdx], t[minIdx]);
        }
    }
    return 0;
}
