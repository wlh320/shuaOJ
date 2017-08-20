// 中序遍历即可
#include <cstdio>
struct Node
{
    char data[12];
    int l, r;
};

Node t[22];
bool show[22];
int root;
bool brace(int tree)
{
    return (t[tree].l != -1 || t[tree].r != -1) && tree != root;
}
void inorder(int tree)
{
    if (tree != -1) {
        if (brace(tree))
            printf("(");
        inorder(t[tree].l);
        printf("%s", t[tree].data);
        inorder(t[tree].r);
        if (brace(tree))
            printf(")");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%s %d %d", t[i].data, &t[i].l, &t[i].r);
        if(t[i].l!=-1) show[t[i].l] = true;
        if(t[i].r!=-1) show[t[i].r] = true;
    }
    for(root = 1; show[root]; ++root);
    inorder(root);
    return 0;
}
