// same as B-1075
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int addr;
    int val;
    int next;
};
Node l[100001];
int main()
{
    vector<Node> minus;
    vector<Node> same;
    vector<Node> greater;
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    for(int i = 0; i < n; ++i) {
        int addr;
        scanf("%d", &addr);
        l[addr].addr = addr;
        scanf("%d %d", &l[addr].val, &l[addr].next);
    }
    for(int p = head; p != -1; p = l[p].next) {
        int val = l[p].val;
        if (val < 0) {
            minus.push_back(l[p]);
        } else if (val >= 0 && val <= k) {
            same.push_back(l[p]);
        } else {
            greater.push_back(l[p]);
        }
    }
    vector<Node> ans(minus);
    ans.insert(ans.end(), same.begin(), same.end());
    ans.insert(ans.end(), greater.begin(), greater.end());
    int sz = ans.size();
    if (sz == 0) {
        printf("-1\n"); 
    } else {
        for(int i = 0; i < sz-1; ++i)
            printf("%05d %d %05d\n", ans[i].addr, ans[i].val, ans[i+1].addr);
        printf("%05d %d -1\n", ans[sz-1].addr, ans[sz-1].val);
    }
    return 0;
}
