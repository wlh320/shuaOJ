#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<int> cors[26*26*26*10];
int str2int(const char *name)
{
    return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10
           +(name[2]-'A')*10+(name[3]-'0');
}

int main()
{
    int n, k; // n-stud k-cors
    scanf("%d %d", &n, &k);
    int cno, sno, ns;
    char name[5];
    for(int i = 0; i < k; ++i) {
        scanf("%d %d", &cno, &ns);
        for(int j = 0; j < ns; ++j) {
            scanf("%s", name);
            sno = str2int(name);
            cors[sno].push_back(cno);
        }
        
    }
    int size;
    for(int i = 0; i < n; ++i) {
        scanf("%s", name);
        sno = str2int(name);
        size = cors[sno].size();
        sort(cors[sno].begin(), cors[sno].end());
        printf("%s %d", name, size);
        for(int j = 0; j < size; ++j) {
            printf(" %d", cors[sno][j]);
        }
        printf("\n");
    }
    return 0;
}
