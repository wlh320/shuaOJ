#include <cstdio>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;
struct Node
{
    int addr;
    int val;
    int next;
};
Node l[100001];
int main()
{
    int n, head;
    int tmp;
    scanf("%d %d", &head, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        scanf("%d %d", &l[tmp].val, &l[tmp].next);
        l[tmp].addr = tmp;
    }
    vector<Node> list;
    vector<Node> drop;
    map<int, int> exist;
    for(int p = head; p != -1; p = l[p].next) {
        if (exist[abs(l[p].val)]) {
            drop.push_back(l[p]);
        } else {
            list.push_back(l[p]);
        }
        exist[abs(l[p].val)]++;
    }
    for(int i = 0; i < list.size(); ++i) {
        if (i != list.size()-1) {
            printf("%05d %d %05d\n", list[i].addr, list[i].val, list[i+1].addr);
        } else {
            printf("%05d %d -1\n", list[i].addr, list[i].val);
        }
    }
    for(int i = 0; i < drop.size(); ++i) {
        if (i != drop.size()-1) {
            printf("%05d %d %05d\n", drop[i].addr, drop[i].val, drop[i+1].addr);
        } else {
            printf("%05d %d -1\n", drop[i].addr, drop[i].val);
        }
    }
    return 0;
}
