// 给出先序遍历,找到BST的分割点,递归建树
#include <cstdio>
int pre[1000];
struct Node
{
    int val;
    Node *l, *r;
    Node(int v) : val(v), l(NULL), r(NULL) {}
};
bool yes = true;
int cnt = 0;
Node* build(int l, int r)
{
    if (l > r) { return NULL; }
    int rt = r+1;
    int pivot = pre[l];
    for(int i = l+1; i <= r; ++i) {
        if (pre[i] >= pivot) {
            rt = i;
            break;
        }
    }
    for(int i = rt+1; i <= r; ++i) {
        if (pre[i] < pivot) {
            yes = false;
            break;
        }
    }
    Node *root = new Node(pivot);
    if (yes && l < r) {
        root->l = build(l+1, rt-1);
        root->r = build(rt, r);
    }
    return root;
}
Node* buildM(int l, int r)
{
    if (l > r) { return NULL; }
    int rt = r+1;
    int pivot = pre[l];
    for(int i = l+1; i <= r; ++i) {
        if (pre[i] < pivot) {
            rt = i;
            break;
        }
    }
    for(int i = rt+1; i <= r; ++i) {
        if (pre[i] >= pivot) {
            yes = false;
            break;
        }
    }
    Node *root = new Node(pivot);
    if (yes && l < r) {
        root->l = buildM(l+1, rt-1);
        root->r = buildM(rt, r);
    }
    return root;
}
void post(Node *root)
{
    if (root) {
        post(root->l);
        post(root->r);
        if(cnt != 0) printf(" ");
        printf("%d", root->val);
        cnt++;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    Node *root = build(0, n-1);
    if (!yes) {
        yes = true;
        root = buildM(0, n-1);
        if (!yes) { 
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    post(root);
    return 0;
}
