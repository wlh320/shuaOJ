#include <cstdio>
#include <map>
using namespace std;
map<int, int> m;
int num[100001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        m[num[i]]++;
    }

    for(int i = 0; i < n; ++i) {
        if (m[num[i]] == 1) {
            printf("%d\n", num[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
