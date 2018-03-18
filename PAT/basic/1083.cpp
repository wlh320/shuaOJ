#include <cmath>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    map<int, int> counter;
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        int diff = abs(num - i);
        if (counter.find(diff) != counter.end()) {
            counter[diff]++;
        } else {
            counter[diff] = 1;
        }
    }
    for (auto it = counter.rbegin(); it != counter.rend(); ++it) {
        if (it->second > 1) {
            printf("%d %d\n", it->first, it->second);
        }
    }

    return 0;
}
