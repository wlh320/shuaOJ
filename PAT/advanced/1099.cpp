// 数组排序 中序遍历建树 层次遍历输出
#include <cstdio>
#include <queue>
#include <algorithm>
struct Node
{
    int l, r;
    int val;
    Node(){l=r=-1;}
};
Node t[100];
int arr[100];
int idx;
bool flag = false;
void inorder(int root)
{
    if (root != -1) {
        inorder(t[root].l);
        t[root].val = arr[idx++];
        inorder(t[root].r);
    }
}

void level()
{
    std::queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int p = q.front();
        if (t[p].l != -1) q.push(t[p].l);
        if (t[p].r != -1) q.push(t[p].r);
        if (flag) {
            printf(" %d", t[p].val);
        } else {
            printf("%d", t[p].val);
            flag = true;
        }
        q.pop();
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &t[i].l, &t[i].r);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+n);
    inorder(0);
    level();
    return 0;
}
