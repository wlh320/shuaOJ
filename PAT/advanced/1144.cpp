#include <climits>
#include <cstdio>
#include <set>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0) {
            s.insert(tmp);
        }
    }
    for (int i = 1; i <= INT_MAX; i++) {
        if (s.find(i) == s.end()) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
