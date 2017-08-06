#include <cstdio>
int main()
{
    int N, D;
    double e;
    int hept = 0, ept = 0;// half empty / empty
    scanf("%d %lf %d\n", &N, &e, &D);
    for(int i = 0; i < N; ++i){
        int nday;
        int eday = 0;
        scanf("%d", &nday);
        for(int j = 0; j < nday; ++j) {
            double kwh;
            scanf("%lf", &kwh);
            if (kwh < e) {
                eday++;
            }
        }
        if (double(eday)/nday > 0.5) {
            if (nday > D) {
                ept++;
            } else {
                hept++;
            }
        }
    }
    printf("%.1f%% %.1f%%\n", double(hept)/N*100, double(ept)/N*100);
    return 0;
}
