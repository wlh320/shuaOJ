// same as B-1030
#include <cstdio>
#include <algorithm>
long long int arr[100000];
int main()
{
    long long int n, p;
    scanf("%lld %lld", &n, &p);
    for(int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
    std::sort(arr, arr+n);
    int max_len = 0;
    int prev_j = 0;
    for(int i = 0; i < n; ++i) {
        int j;
        for(j = prev_j; j < n; ++j) {
            if (arr[j] > arr[i]*p) {
                break;
            }
        }
        if (j < n) {
            max_len = (j-i) > max_len ? (j-i):max_len;
            prev_j = j-1;
        } else {
            max_len = (n-i) > max_len ? (n-i):max_len;
            prev_j = n;
        }
    }
    printf("%d\n", max_len);
    return 0;
}
