#include <cstdio>
#include <vector>
using namespace std;
int n;
int heap[1024];
vector<int> v;
void dfs(int x)
{
    if (2 * x > n && 2 * x + 1 > n) {
        for (unsigned int i = 0; i < v.size(); i++) {
            printf("%d ", v[i]);
        }
        printf("%d\n", heap[x]);
        return;
    }
    v.push_back(heap[x]);
    if (2 * x + 1 <= n)
        dfs(2 * x + 1);
    if (2 * x <= n)
        dfs(2 * x);
    v.pop_back();
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
    }
    dfs(1);
    bool is_max = true;
    bool is_min = true;
    // compare each node to its parent
    for (int i = 2; i <= n; i++) {
        if (heap[i] > heap[i / 2]) {
            is_max = false;
        }
        if (heap[i] < heap[i / 2]) {
            is_min = false;
        }
    }
    if (is_max) {
        printf("Max");
    } else if (is_min) {
        printf("Min");
    } else {
        printf("Not");
    }
    printf(" Heap\n");
    return 0;
}