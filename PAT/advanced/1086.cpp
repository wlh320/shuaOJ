// 非递归中序遍历, push顺序是前序, pop顺序是中序
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
int pre[32];
int in[32];
int post[32];

void build(int pl, int pr, int il, int ir, int pos)
{
    if (pl > pr) return ;
    int pivot = pre[pl];
    int p = il;
    while(in[p] != pivot) p++;
    post[pos] = pivot;
    build(pl+1, pl+p-il, il, p-1, pos-(ir-p)-1); // left
    build(pl+p-il+1, pr, p+1, ir, pos-1); // right
}

int main()
{
    int n;
    scanf("%d", &n);
    stack<int> s;
    int cntIn = 0, cntPre = 0, tmp;
    char cmd[8];
    for(int i = 0; i < n+n; ++i) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "Push")) { // pre
            scanf("%d", &tmp);
            pre[cntPre++] = tmp;
            s.push(tmp);
        } else if (!strcmp(cmd, "Pop")) { // in
            tmp = s.top();
            in[cntIn++] = tmp;
            s.pop();
        }
    }
    build(0, n-1, 0, n-1, n-1);
    for(int i = 0; i < n; ++i) {
        if (i != 0) putchar(' ');
        printf("%d", post[i]);
    }
    return 0;
}
