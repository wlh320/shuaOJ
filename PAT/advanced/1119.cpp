// 给出前序和后序,递归判断构建的树是否唯一
#include <cstdio>
int pre[32];
int post[32];
struct Node
{
    int l, r;
    Node(): l(-1), r(-1) {}
};
Node t[10000];
bool flag = true;
int build(int prel, int prer, int pol, int por)
{
    int root = pre[prel];
    if (prel > prer) {
        return -1;
    } else if (prel == prer) {
        return root;
    }
    int idx = 0;
    for(idx = prel + 1; idx <= prer; ++idx) {
        if (pre[idx] == post[por-1]) break;
    }
    if (idx - prel > 1) { // 正常
        t[root].l = build(prel+1,idx-1,pol,pol+idx-prel-2);
        t[root].r = build(idx,prer,pol+idx-prel-1,por-1);

    } else { // 出现歧义
        flag = false;
        t[root].r = build(idx,prer,pol+idx-prel-1,por-1);
    }
    return root;
}
bool start = true;
void inorder(int root)
{
    if (root != -1) {
        inorder(t[root].l);
        if (!start) printf(" ");
        printf("%d", root);
        start = false;
        inorder(t[root].r);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    for(int i = 0; i < n; ++i) scanf("%d", &post[i]);
    int root = build(0, n-1, 0, n-1);
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    inorder(root);
    printf("\n");
    return 0;
}
