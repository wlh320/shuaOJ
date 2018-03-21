#include <cstdio>
int tree[1004];
int size;
bool first = true;
int left(int root) { return root * 2 > size ? 0 : root * 2; }
int right(int root) { return root * 2 + 1 > size ? 0 : root * 2 + 1; }
void check_heap()
{
    bool isMax = true;
    bool isMin = true;
    for (int i = 1; i <= size; ++i) {
        int v = tree[i];
        int lv = left(i) == 0 ? tree[i] : tree[left(i)];
        int rv = right(i) == 0 ? tree[i] : tree[right(i)];
        if (!(v >= lv && v >= rv)) {
            isMax = false;
        }
        if (!(v <= lv && v <= rv)) {
            isMin = false;
        }
    }
    if (isMax) {
        printf("Max Heap\n");
    } else if (isMin) {
        printf("Min Heap\n");
    } else {
        printf("Not Heap\n");
    }
}
void post_order(int root)
{
    if (root) {
        post_order(left(root));
        post_order(right(root));
        if (!first)
            putchar(' ');
        printf("%d", tree[root]);
        first = false;
    }
}
int main()
{
    int n;
    scanf("%d %d", &n, &size);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= size; ++j) {
            scanf("%d", &tree[j]);
        }
        check_heap();
        first = true;
        post_order(1);
        printf("\n");
    }
    return 0;
}
