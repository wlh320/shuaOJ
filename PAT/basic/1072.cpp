#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int banned[6];

int main()
{
    int n, m;
    int stuCnt = 0, itmCnt = 0; 
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &banned[i]);
    }

    for(int i = 0; i < n; ++i) { // every student
        char name[5];
        int ni;
        vector<int> chkout;
        scanf("%s %d", name, &ni);
        for(int j = 0; j < ni; ++j) { // every item
            int item;
            scanf("%d", &item);
            for(int k = 0; k < m; ++k) { // check
                if (item == banned[k]) {
                    itmCnt++;
                    chkout.push_back(item);
                }
            }
        }
        if (chkout.size() != 0) {
            stuCnt++;
            printf("%s:", name);
            for(int k = 0; k < chkout.size(); ++k) {
                printf(" %04d", chkout[k]);
            }
            printf("\n");
        }
    }
    printf("%d %d\n", stuCnt, itmCnt);
    return 0;
}
