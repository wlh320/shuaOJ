#include <cstdio>
#include <cmath>
int Tsize;
bool used[10008]; // 10007: minimum prime > 10000
bool isPrime(int n)
{
    if (n <= 1) return false;
    int sq = sqrt(n);
    for(int i = 2; i <= sq; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int h(int key) {
    return key % Tsize;
}
int getPos(int key, int d)
{
    return (h(key) + d*d) % Tsize;
}
int main()
{
    int n;
    int key, pos, d;
    scanf("%d %d", &Tsize, &n);
    while(!isPrime(Tsize)) Tsize++;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &key);
        for(d = 0; d < Tsize; ++d) {
            pos = getPos(key, d);
            if (!used[pos]) {
                used[pos] = true;
                if (i != 0) putchar(' ');
                printf("%d", pos);
                break;
            }
        }
        if (d >= Tsize) {
            if (i != 0) putchar(' ');
            putchar('-'); 
        }
    }
    return 0;
}
