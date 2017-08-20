#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int ori[101]; // origin
int tgt[101]; // target
bool same(const int *a, const int *b, int n)
{
    for(int i = 0; i < n; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}
void print_arr(int *a, int n) 
{
    for(int i = 0; i < n; ++i) {
        if (i == 0)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
    printf("\n");
}

bool insert(int n)
{
    int i, j;
    for(i = 0; i < n-1 && tgt[i] <= tgt[i+1]; ++i);
    for(j = i + 1; j < n && ori[j] == tgt[j]; ++j);
    if (j == n) {
        printf("Insertion Sort\n");
        sort(ori, ori+i+2);
        print_arr(ori, n);
        return true;
    } else {
        return false;
    }
}

void heap(int n)
{
    int i = 0;
    printf("Heap Sort\n");
    make_heap(ori, ori+n);
    while(!same(ori, tgt, n)) {
        pop_heap(ori, ori+n-i);
        i++;
    }
    pop_heap(ori, ori+n-i);
    print_arr(ori, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &ori[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &tgt[i]);
    }
    if (!insert(n)) {
        heap(n);
    }
    return 0;
}
