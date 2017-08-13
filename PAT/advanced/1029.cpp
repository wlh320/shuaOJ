#include <cstdio>
int num1[1000000];
int num2[1000000];
int main()
{
    int n1, n2;
    scanf("%d", &n1);
    for(int i = 0; i < n1; ++i) {
        scanf("%d", &num1[i]);
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; ++i) {
        scanf("%d", &num2[i]);
    }
    int mid = (n1+n2-1) / 2;
    int p1 = 0, p2 = 0;
    int cnt = -1;
    int flag = 1;
    while(p1 < n1 && p2 < n2 && cnt < mid) {
        while(p1 < n1 && num1[p1] < num2[p2] && cnt < mid) {
            cnt++;
            p1++;
            flag = 1;
        }
        while(p2 < n2 && num2[p2] < num1[p1] && cnt < mid) {
            cnt++;
            p2++;
            flag = 2;
        }
    }
    if (cnt == mid) {
        printf("%d\n", flag == 1?num1[p1-1]:num2[p2-1]);
        return 0;
    }
    while(p1 < n1 && cnt < mid) {
        cnt++;
        if (cnt == mid) {
            printf("%d\n", num1[p1]);
            return 0;
        }
        p1++;
    }
    while(p2 < n2 && cnt < mid) {
        cnt++;
        if (cnt == mid) {
            printf("%d\n", num2[p2]);
            return 0;
        }
        p2++;
    }
    return 0;
}
