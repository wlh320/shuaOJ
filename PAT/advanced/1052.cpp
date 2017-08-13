#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Node 
{
    int addr;
    int val;
    int next;
};
bool cmp(Node a, Node b){return a.val < b.val;}
Node nodes[100000];
int main()
{
    vector<Node> list;
    int n, head;
    scanf("%d %d", &n, &head);
    int addr;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &addr);
        nodes[addr].addr = addr;
        scanf("%d %d", &nodes[addr].val, &nodes[addr].next);
    }
    for(addr = head; addr != -1; addr = nodes[addr].next) {
        list.push_back(nodes[addr]);
    }
    sort(list.begin(), list.end(), cmp);
    int size = list.size();
    if (size == 0) {
        printf("0 -1\n");
    } else {
        printf("%d %05d\n", size, list[0].addr);
        for(int i = 0; i < size; ++i) {
            if (i != size - 1) {
                printf("%05d %d %05d\n", list[i].addr, list[i].val, list[i+1].addr);
            } else {
                printf("%05d %d -1\n", list[i].addr, list[i].val);
            }
        }
    }
    return 0;
}
