#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int hash_addr(int val, int tsize) { return val % tsize; }
void insert(vector<int>& v, int tsize, int val)
{
    for (int i = 0; i < tsize; i++) {
        int addr = hash_addr(val + i * i, tsize);
        if (v[addr] == 0) {
            v[addr] = val;
            return;
        }
    }
    printf("%d cannot be inserted.\n", val);
}
int search(vector<int>& v, int tsize, int val)
{
    int cnt = 0;
    for (int i = 0; i < tsize; i++) {
        int addr = hash_addr(val + i * i, tsize);
        cnt++;
        if (v[addr] == val || v[addr] == 0) {
            return cnt;
        }
    }
    return cnt + 1;
}
int main()
{
    int tsize, n, m;
    scanf("%d %d %d", &tsize, &n, &m);
    while (!isPrime(tsize)) {
        tsize++;
    }
    vector<int> v(tsize);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        insert(v, tsize, num);
    }
    int search_times = 0;
    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        search_times += search(v, tsize, num);
    }
    printf("%.1lf\n", double(search_times) / m);
    return 0;
}
