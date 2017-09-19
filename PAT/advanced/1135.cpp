// 首先根据前序中序建树, 然后判断是否红黑树
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
enum Type {RED, BLK};

struct RBNode
{
    int val;
    RBNode *l, *r;
    Type type;
    RBNode(int v) {
        l = r = NULL;
        type = v < 0 ? RED: BLK;
        val = abs(v);
    }
};

RBNode* build(vector<int> &pre, vector<int> &in, int pl, int pr, int il, int ir)
{
    if (pl > pr) return NULL;
    RBNode *root = new RBNode(pre[pl]);
    int p = il;
    while(in[p] != pre[pl] && p <= ir) p++;
    root->l = build(pre, in, pl+1, pl+p-il, il, p-1);
    root->r = build(pre, in, pl+p-il+1, pr, p+1, ir);
    return root;
}

bool cmp(const int a, const int b) {
    return abs(a) < abs(b);
}

bool isBlack(RBNode *t)
{
    return t == NULL || t->type == BLK;
}

bool checkRED(RBNode *t)
{
    return isBlack(t->l) && isBlack(t->r);
}

// return cnt of black
int checkRB(RBNode *root, bool &res)
{
    if (root) {
        int lb = checkRB(root->l, res);
        int rb = checkRB(root->r, res);
        if (root->type == RED && !checkRED(root)) {
            res = false;
        }
        if (lb != rb) res = false;
        return root->type == BLK ? lb+1 : lb;
    }
    return 1; // NULL return 1 cuz is black
}

bool isRBTree(RBNode *root)
{
    if (!root) return true;
    if (root->type == RED) {
        return false;
    }
    bool res = true;
    checkRB(root, res);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        int sz;
        scanf("%d", &sz);
        vector<int> pre(sz, 0);
        for(int i = 0; i < sz; ++i) {
            scanf("%d", &pre[i]);
        }
        vector<int> in(pre);
        sort(in.begin(), in.end(), cmp);
        RBNode *tree = build(pre, in, 0, sz-1, 0, sz-1);
        if(!isRBTree(tree)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
