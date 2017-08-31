// AVL树插入 + BFS判断是否完全二叉树
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int val; // value
    int h; // height
    Node *l, *r;
    Node(int val) : val(val), h(1), l(NULL), r(NULL) {}
};
inline int height(Node *t) 
{
    if (t == NULL) return 0;
    return t->h;
}
bool isBalanced(Node *root)
{
    return abs((height(root->l) - height(root->r))) < 2;
}

Node *LL(Node *root)
{
    Node *rch = root->r;
    root->r = rch->l;
    rch->l = root;
    root->h = std::max(height(root->l), height(root->r))+1;
    rch->h = std::max(height(rch->l), height(rch->l))+1;
    return rch;
}
Node *RR(Node *root)
{
    Node *lch = root->l;
    root->l = lch->r;
    lch->r = root;
    root->h = std::max(height(root->l), height(root->r))+1;
    lch->h = std::max(height(lch->l), height(lch->r))+1;
    return lch;
}
Node *LR(Node *root)
{
    root->l = LL(root->l);
    return RR(root);
}
Node *RL(Node *root)
{
    root->r = RR(root->r);
    return LL(root);
}

Node *insert(Node *root, int val)
{
    if (root == NULL) {
        root = new Node(val);
    } else if (val > root->val) {
        root->r = insert(root->r, val);
        if (!isBalanced(root)) {
            if (val > root->r->val) { // 插右右, 左旋
                root = LL(root);
            } else if (val < root->r->val) { // 插右左, 先左旋再右旋
                root = RL(root);
            }
        }
    } else if (val < root->val) {
        root->l = insert(root->l, val);
        if (!isBalanced(root)) {
            if (val < root->l->val) { // 插左左, 右旋
                root = RR(root);
            } else if (val > root->l->val) { // 插左右, 先右旋再左旋
                root = LR(root);
            }
        }
    }
    root->h = std::max(height(root->l), height(root->r))+1;
    return root;
}

bool isComplete(Node *root)
{
    bool flag = false;
    bool ans = true;
    bool first = true;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *p = q.front();
        if (p == NULL) {
            flag = true;
        } else {
            if (!first) printf(" ");
            printf("%d", p->val);
            first = false; 
            if (flag) ans = false; // 遍历过程NULL之后又出现节点
        }
        if (p) q.push(p->l);
        if (p) q.push(p->r);
        q.pop();
    }
    printf("\n");
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *root = NULL;
    int tmp;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        root = insert(root, tmp);
    }
    if (isComplete(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
