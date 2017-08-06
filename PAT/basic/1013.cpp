#include <cstdio>
#include <cmath>

int prime[10001];

bool is_prime(int n)
{
    for(int i = 2; i <= int(sqrt(n)); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int start, end;
    int line1st = true;
    int cnt10 = 0;

    prime[1] = 2;
    int j = 2;
    for(int i = 3; j != 10001; i+=2) {
        if(is_prime(i))
            prime[j++] = i;
    }

    scanf("%d %d", &start, &end);
    for(int i = start; i <= end; ++i) {
        if (cnt10 % 10 == 0 && cnt10 != 0){ printf("\n");line1st=true;}
        if (line1st) {
            line1st = false;
            printf("%d", prime[i]);
        } else
            printf(" %d", prime[i]);
        cnt10++;
    }
}
