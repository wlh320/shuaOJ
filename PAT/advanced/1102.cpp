#include <cstdio>
#include <queue>
using namespace std;
struct Node
{
    int l, r, p; // left right parent
    Node() {l=r=p=-1;}
};
Node t[11];
int root;
bool flag;

inline int ch2int(char ch) 
{
    if (ch >= '0' && ch <= '9') {
        return ch -'0';
    } else {
        return -1;
    }
}
inline void print(int r)
{
    if (flag) {
        printf(" %d", r);
    } else {
        printf("%d", r);
    }
    flag = true;
}
void inorder(int r)
{
    if (r != -1) {
        inorder(t[r].l);
        print(r);
        inorder(t[r].r);
    }
}
void level(int r)
{
    queue<int> q;
    q.push(r);
    int p;
    while(!q.empty()) {
        p = q.front();
        print(p);
        if (t[p].l != -1) q.push(t[p].l);
        if (t[p].r != -1) q.push(t[p].r);
        q.pop();
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; ++i) {
        // trick: save inverted tree
        t[i].r = ch2int(getchar());
        getchar();
        t[i].l = ch2int(getchar());
        getchar();
        t[t[i].l].p = i;
        t[t[i].r].p = i;
    }
    while(t[root].p != -1) {
        root = t[root].p;
    }
    flag = false;
    level(root);
    printf("\n");
    flag = false;
    inorder(root);
    printf("\n");
    return 0;
}
