#include <cstdio>
float max3(float n[3])
{
    return n[0] >= n[1] ? (n[0] >= n[2]? 0 : 2) :
           (n[1] >= n[2]? 1 : 2);
}
int main()
{
    char type[3]={'W','T','L'};
    double res = 1;
    for(int i = 0; i < 3; ++i) {
        float odd[3];
        scanf("%f %f %f", &odd[0], &odd[1], &odd[2]);
        int max = max3(odd);
        putchar(type[max]);
        putchar(' ');
        res *= odd[max];       
    }
    res = (res*0.65-1)*2+0.005;
    printf("%.2lf\n", res);
    return 0;
}
