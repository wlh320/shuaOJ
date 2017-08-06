#include <cstdio>
#include <cmath>
int rank[10000];
bool is_prime(int n)
{
    for(int i = 2; i <= int(sqrt(n)); ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int no;
        scanf("%d", &no);
        rank[no] = i+1;
    }

    int nQuery;
    scanf("%d", &nQuery);
    for(int i = 0; i < nQuery; ++i) {
        int no;
        scanf("%d", &no);
        if (no < 0 || no > 9999 || rank[no] == 0) {
            printf("%04d: Are you kidding?\n", no);
        } else if (rank[no] == -1) {
            printf("%04d: Checked\n", no);
        } else if (rank[no] == 1) {
            printf("%04d: Mystery Award\n", no);
            rank[no] = -1;
        } else if (is_prime(rank[no])) {
            printf("%04d: Minion\n", no);
            rank[no] = -1;
        } else {
            printf("%04d: Chocolate\n", no);
            rank[no] = -1;
        }
    } 
    return 0;
}
