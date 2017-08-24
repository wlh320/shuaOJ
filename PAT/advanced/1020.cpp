// 根据后序和中序递归确定树
#include <cstdio>
#include <queue>
struct Node
{
    int l,r;
    Node(){l=r=-1;}
};
Node t[32]; // tree
int post[32]; // postorder
int in[32]; // inorder

// post-left post-right in-left in-right
int build(int pl, int pr, int il, int ir)
{
    if (pl > pr) {
        return -1;
    }
    int p = il;
    while(post[pr] != in[p]) p++;
    int tree = post[pr];
    t[tree].l = build(pl, pr-ir+p-1, il, p-1);
    t[tree].r = build(pr-ir+p, pr-1, p+1, ir);
    return tree;
}

void level(int root)
{
    std::queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int p = q.front();
        printf("%d", p);
        if (t[p].l != -1) q.push(t[p].l);
        if (t[p].r != -1) q.push(t[p].r); 
        q.pop();
        if (q.size() != 0) printf(" ");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    build(0, n-1, 0, n-1);
    int root = post[n-1];
    level(root);
    return 0;
}
