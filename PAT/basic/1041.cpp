#include <cstdio>
struct Query
{
    char no[15];
    int examNo;
};
Query map[1001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int testNo;
        Query q;
        scanf("%s %d %d", q.no, &testNo, &q.examNo);
        map[testNo] = q;
    }
    int query_n;
    scanf("%d", &query_n);
    for(int i = 0; i < query_n; ++i) {
        int testNo;
        scanf("%d", &testNo);
        printf("%s %d\n", map[testNo].no, map[testNo].examNo);
    }
    return 0;
}
