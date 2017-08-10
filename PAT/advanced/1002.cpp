#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
map<int, double> sum;
int main()
{
    int cnt = 0, k;
    int e;
    double c; 
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d %lf", &e, &c);
        sum[e] = c;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d %lf", &e, &c);
        sum[e] += c;
        if (fabs(sum[e]) < 1e-6) {
            sum.erase(e);
        }
    }
    if (sum.size() == 0) { // 坑爹根本没说0怎么办
        printf("0\n");
    } else {
        printf("%ld ", sum.size());
        map<int, double>::reverse_iterator it = sum.rbegin();
        while(it!=sum.rend()) {
            if (it == sum.rbegin()) {
                printf("%d %.1lf", it->first, it->second);
            } else {
                printf(" %d %.1lf", it->first, it->second);
            }
            it++;
        }
    }
    return 0;
}
