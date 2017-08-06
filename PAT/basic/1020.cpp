#include <cstdio>
#include <algorithm>
struct MoonCake
{
    double cnt;
    double price;
};

MoonCake mc[1000];
bool cmp(MoonCake a, MoonCake b) {return a.price > b.price;}
int main()
{
    int n, limit;
    scanf("%d %d", &n, &limit);
    for(int i = 0; i < n; ++i)
        scanf("%lf", &mc[i].cnt);
    for(int i = 0; i < n; ++i) {
        double tmp;
        scanf("%lf", &tmp);
        mc[i].price = tmp / mc[i].cnt;
    }
    std::sort(mc, mc+n, cmp);
    double cnt = 0;
    double price = 0;
    for(int i = 0; i < n; ++i) {
        if (cnt + mc[i].cnt <= limit) {
            cnt += mc[i].cnt;
            price += (mc[i].cnt)*mc[i].price;
        } else {
            price += (limit-cnt)*mc[i].price;
            break;
        }
    }
    printf("%.2lf\n", price);
    return 0;
}
