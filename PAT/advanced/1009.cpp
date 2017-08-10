#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
map<int, double> a;
map<int, double> prod;
int main()
{
    int k;
    int e;
    double c;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d %lf", &e, &c);
        a[e] = c;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d %lf", &e, &c);
        map<int, double>::iterator it = a.begin();
        while(it != a.end()) {
            int newE = e + it->first;
            double newC = c * it->second;
            prod[newE] += newC;
            if (fabs(prod[newE]) < 0.05) {
                prod.erase(newE);
            }
            ++it;
        }
    }
    if (prod.size() == 0) { // 坑爹根本没说0怎么办
        printf("0\n");
    } else {
        printf("%ld ", prod.size());
        map<int, double>::reverse_iterator it = prod.rbegin();
        while(it!=prod.rend()) {
            if (it == prod.rbegin()) {
                printf("%d %.1lf", it->first, it->second);
            } else {
                printf(" %d %.1lf", it->first, it->second);
            }
            it++;
        }
    }
    return 0;
}
