// 双端队列实现zigzag层次遍历
#include <cstdio>
#include <deque>
struct Node
{
    int l, r;
    Node() {l=r=-1;}
};
Node t[1000];
int post[32];
int in[32];
int build(int pl, int pr, int il, int ir)
{
    if (pl > pr) {
        return -1;
    }
    int p = il;
    while(in[p] != post[pr]) p++;
    int tree = post[pr];
    t[tree].l = build(pl,pr-ir+p-1,il,p-1);
    t[tree].r = build(pr-ir+p,pr-1,p+1,ir);
    return tree;
}
int zigzag(int root)
{
    bool flag = true;
    std::deque<int> q;
    q.push_front(root);
    q.pop_front();
    printf("%d", root);
    if (t[root].r != -1) q.push_back(t[root].r);
    if (t[root].l != -1) q.push_back(t[root].l);
    while(!q.empty()) {
        int sz = q.size();
        flag = !flag;
        while(sz--) {
            if (flag) { // right 2 left
                int p = q.front();
                q.pop_front();
                printf(" %d", p);
                if (t[p].r != -1) q.push_back(t[p].r);
                if (t[p].l != -1) q.push_back(t[p].l);

            } else { // left 2 right
                int p = q.back();
                q.pop_back();
                printf(" %d", p);
                if (t[p].l != -1) q.push_front(t[p].l);
                if (t[p].r != -1) q.push_front(t[p].r);
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    build(0, n-1, 0, n-1);
    int root = post[n-1];
    zigzag(root);
    return 0;
}
