// same as B-1049
#include <cstdio>
int main()
{
    double sum = 0;
    int n;
    scanf("%d\n", &n);
    double tmp;
    for(int i = 0; i < n; ++i) {
        scanf("%lf", &tmp);
        sum += tmp*(n-i)*(i+1); // math problem
    }
    printf("%.2lf\n", sum);
    return 0;
}
