#include <cstdio>
int arr[100];
int main()
{
    int n, n_shift;
    scanf("%d %d", &n, &n_shift);
    n_shift %= n;
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    for(int i = 0; i < n_shift; ++i)
    {
        int tmp = arr[n-1];
        for(int j = n-1; j!= 0; --j)
            arr[j] = arr[j-1];
        arr[0] = tmp;
    }
    printf("%d", arr[0]);
    for(int i = 1; i < n; ++i)
        printf(" %d", arr[i]);
    return 0;
}
