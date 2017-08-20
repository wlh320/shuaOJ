#include <cstdio>
#include <stack>
using namespace std;
int num[1000]; // number
int tgt[1000]; // target
int main()
{
    int n, m, k; // n-num m-max k-query
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < n; ++i) {
        num[i] = i+1;
    }
    int pn, pt;
    while(k--) {
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &tgt[i]);
        }
        pn = pt = 0;
        while(s.size() <= m) {
            if (s.empty() || s.top() != tgt[pt]) {
                s.push(num[pn++]);
            } else {
                s.pop();
                pt++;
            }
            if (pt == n) {
                break;
            }
        }
        if (s.size() < m) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
