#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char name[40000][5];
vector<int> c[2500];
bool cmp(int a, int b)
{
    return strcmp(name[a], name[b]) < 0;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%s", name[i]);
        int nc, course;
        scanf("%d", &nc);
        for(int j = 0; j < nc; ++j) {
            scanf("%d", &course);
            c[course-1].push_back(i);
        }
    }

    for(int i = 0; i < k; ++i) {
        int size = c[i].size();
        printf("%d %d\n", i+1, size);
        sort(c[i].begin(), c[i].end(), cmp);
        for(int j = 0; j < size; ++j) {
            printf("%s\n", name[c[i][j]]);
        }
    }
    return 0;
}
