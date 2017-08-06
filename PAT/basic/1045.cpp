#include <cstdio>
#include <algorithm>
#define MIN -1
#define MAX 2147483647

int arr[100000];
int left[100000]; // 0~i-1 max
int right[100000]; // i+1~n-1 min
int yes[100000];
void print(int *a, int n)
{
    for(int i = 0; i < n; ++i) {
        if (i == 0)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    left[0] = MIN;
    right[n-1] = MAX; 
    for(int i = 1; i < n; ++i) {
        left[i] = arr[i-1] > left[i-1] ? arr[i-1]: left[i-1];
    }
    for(int i = n - 2; i >= 0; --i) {
        right[i] = arr[i+1] < right[i+1] ? arr[i+1]: right[i+1];
    }
    int j = 0;
    for(int i = 0; i < n; ++i) {
        if (left[i] < arr[i] && right[i] > arr[i]) {
            yes[j++] = arr[i];
        }
    }
    std::sort(yes, yes+j);
    printf("%d\n", j);
    print(yes, j);
    return 0;
}
