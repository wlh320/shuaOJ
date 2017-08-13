#include <cstdio>
struct Node
{
    char ch;
    int next;
};
Node m[100000];
bool visit[100000];
int main()
{
    int ahead, bhead, n;
    int addr, next;
    char tmpch;
    scanf("%d %d %d", &ahead, &bhead, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %c %d", &addr, &tmpch, &next);
        m[addr].ch = tmpch;
        m[addr].next = next;
    }
    int p;
    for(p = ahead; p != -1; p = m[p].next) {
        visit[p] = true;
    }
    for(p = bhead; p != -1; p = m[p].next) {
        if (visit[p]) {
            printf("%05d\n", p);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
