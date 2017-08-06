#include <cstdio>
#include <algorithm>
using namespace std;
int num[100001];
bool cmp(int a, int b){return a>b;}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    sort(num, num+n, cmp);
    int max = 0;
    for(int i = 0; i < n; ++i) {
        if(num[i] > max+1)
            max++;
    }
    printf("%d\n", max);
    return 0;
}
