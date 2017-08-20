#include <cstdio>
#include <algorithm>
int arr[100000];
int getFirst(int *a, int l, int r)
{
    for(int i = l; i < r; ++i) {
        if (a[i] != i) {
            return i;
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int cnt = 0;
    int first = getFirst(arr, 1, n);
    while(first) {
        if (arr[0] == 0) {
            std::swap(arr[0], arr[first]);
            cnt++;
        }
        while(arr[0] != 0) {
            int tmp = arr[0];
            std::swap(arr[0], arr[tmp]);
            printf("%d\n", tmp);
            cnt++;
        }
        first = getFirst(arr, first, n);
    }
    printf("%d\n", cnt);
    return 0;
}
