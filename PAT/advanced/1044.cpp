// 求所有数组的片段和大于并最接近目标值
// 考虑到累加和递增, 用二分搜索降低复杂度才能过
#include <cstdio>
#include <list>
using namespace std;
struct Node
{
    int l, r;
    Node(int l, int r) : l(l), r(r) {}
};
list<Node> ans;
int cumsum[100001];
int main()
{
    int n, tgt;
    scanf("%d %d", &n, &tgt);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &cumsum[i]);
        cumsum[i] += cumsum[i-1];
    }    
    int l, r, mid, val, minsum = 999999999;
    for(int i = 0; i <= n; ++i) {
        l = i+1; r = n;
        while (l < r) { // 不是精确的搜索,搜到最接近的为止
            mid = (l+r)/2;
            val = cumsum[mid] - cumsum[i];
            if (val >= tgt) {
                r = mid;
            } else if (val < tgt) {
                l = mid + 1;
            }
        }
        val = cumsum[r] - cumsum[i];
        if (val >= tgt) {
            if (val == minsum) {
                ans.push_back(Node(i+1, r));
            } else if (val < minsum) {
                minsum = val;
                ans.clear();
                ans.push_back(Node(i+1, r));
            }
        }
    }
    list<Node>::iterator it;
    for(it = ans.begin(); it != ans.end(); ++it) {
        printf("%d-%d\n", it->l, it->r);
    }
    return 0;
}
