#include <cstdio>
#include <queue>
using namespace std;
struct Node
{
    int p,l,r;
    Node(){p=l=r=-1;}
};
Node t[20];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int l = -1, r = -1;
        scanf("%d", &l);
        scanf("%d", &r);
        t[i].l = l; t[i].r = r;
        t[l].p = i; t[r].p = i;
    }
    int root = 0;
    int last = 0;
    bool flag = false;
    while(t[root].p != -1) root = t[root].p;
    queue<int> q; // 层次遍历
    q.push(root);
    while(!q.empty()) {
        int p = q.front();
        if (p != -1) { // -1之后又出现节点,不是CBT
            q.push(t[p].l);
            q.push(t[p].r);
            last = p;
            if (flag) {
                printf("NO %d\n", root);
                return 0;
            }
        } else { // 出现过-1,设标志位
            flag = true;
        }
        q.pop();
    }
    printf("YES %d\n", last);
    return 0;
}
