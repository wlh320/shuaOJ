// 建立BST并统计每层节点个数
#include <cstdio>
struct Node
{
    int val;
    Node *l, *r;
    Node(int v){val=v;l=r=NULL;}
};
int cnt[1002];
int lvl;
Node* insert(Node *t, int v, int l)
{
    if (t == NULL) {
        t = new Node(v);
        lvl = l > lvl? l: lvl;
        cnt[l]++;
    } else if (v <= t->val) { // left
        t->l = insert(t->l, v, l+1);
    } else { // right
        t->r = insert(t->r, v, l+1);
    }
    return t;
}

int main()
{
    int n;
    scanf("%d", &n);
    int tmp;
    Node *root = NULL;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        root = insert(root, tmp, 0);
    }
    int n1 = cnt[lvl];
    int n2 = cnt[lvl-1];
    printf("%d + %d = %d\n", n1, n2, n1+n2);
    return 0;
}
