// 没看题，原来是先序遍历，我说怎么建树老超时......
#include <cstdio>
#include <vector>
using namespace std;
struct Node {
    int val;
    int left;
    int right;
    Node(int v = 0)
    {
        val = v;
        left = right = -1;
    }
};
Node t[10004];
void pre(int l, int r)
{
    if (l <= r) {
        int r_start = r + 1;
        for (int i = l + 1; i <= r; ++i) {
            if (t[i].val >= t[l].val) {
                r_start = i;
                break;
            }
        }
        if (l + 1 <= r)
            t[l].left = l + 1;
        if (r_start <= r)
            t[l].right = r_start;
        pre(l + 1, r_start - 1);
        pre(r_start, r);
    }
}

// 找节点时记录线路
int search(int root, int val, vector<int>& path)
{
    while (root != -1 && t[root].val != val) {
        path.push_back(t[root].val);
        if (val < t[root].val)
            root = t[root].left;
        else
            root = t[root].right;
    }
    path.push_back(val);
    return root;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i].val);
    }
    pre(0, n - 1);
    root = 0;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        vector<int> p1, p2;
        int t1 = search(root, v1, p1);
        int t2 = search(root, v2, p2);
        if (t1 != -1 && t2 != -1) { // have LCA
            int v = t[root].val;
            // 线路中最后一个相同的即为LCA
            for (unsigned int i = 0; i < min(p1.size(), p2.size()); i++) {
                if (p1[i] == p2[i]) {
                    v = p1[i];
                } else {
                    break;
                }
            }
            if (v == v1) {
                printf("%d is an ancestor of %d.\n", v1, v2);
            } else if (v == v2) {
                printf("%d is an ancestor of %d.\n", v2, v1);
            } else {
                printf("LCA of %d and %d is %d.\n", v1, v2, v);
            }
        } else if (t1 != -1 && t2 == -1) {
            printf("ERROR: %d is not found.\n", v2);
        } else if (t1 == -1 && t2 != -1) {
            printf("ERROR: %d is not found.\n", v1);
        } else {
            printf("ERROR: %d and %d are not found.\n", v1, v2);
        }
    }
    return 0;
}
