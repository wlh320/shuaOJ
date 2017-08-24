// 维护栈的同时查询中位数-树状数组(binary indexed tree)
// 累计每个数出现的个数,用树状数组O(logn)找中位数
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
inline int lowbit(int x) { return x&(-x);} // 求第一个1
const int MAX = 100001;
int cnt[MAX]; // cum sum of <=i
stack<int> s; // stack
void add(int x, int v)
{
    for(int i = x; i < MAX; i += lowbit(i)) {
        cnt[i] += v;
    }
}

int get(int x)
{
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i)) {
        sum += cnt[i];
    }
    return sum;
}

int peek()
{
    int pos = (s.size()+1)/2;
    int l = 1, r = MAX, mid = (l+r)/2;
    while (l < r) {
        mid = (l+r)/2;
        if (get(mid) < pos) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main()
{
    int n, tmp;
    scanf("%d", &n);
    char cmd[16];
    while(n--) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "Push")) {
            scanf("%d", &tmp);
            s.push(tmp);
            add(tmp, 1);
        } else if (!s.empty()) {
            if (!strcmp(cmd, "Pop")) {
                printf("%d\n", s.top());
                add(s.top(), -1);
                s.pop(); 
            } else if (!strcmp(cmd, "PeekMedian")) {
                printf("%d\n", peek());                
            }
        } else { // size == 0
            printf("Invalid\n");
        }
    }
    return 0;
}
