#include <cstdio>
#include <set>
using namespace std;
set<int> s[50];
int main()
{
    int n, nSet, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &nSet);
        for(int j = 0; j < nSet; ++j) {
            scanf("%d", &tmp);
            s[i].insert(tmp);
        }
    }
    int nQuery, s1, s2;
    scanf("%d", &nQuery);
    int nc, nt;
    set<int>::iterator it;
    for(int i = 0; i < nQuery; ++i) {
        scanf("%d %d", &s1, &s2);
        s1--;s2--;
        nt = s[s2].size();
        for(it = s[s1].begin(); it != s[s1].end(); ++it) {
            if (s[s2].find(*it) == s[s2].end()) {
                nt++;
            }
        }
        nc = s[s1].size()+s[s2].size()-nt;
        printf("%.1lf%%\n", nc/double(nt)*100);
    }
    return 0;
}
