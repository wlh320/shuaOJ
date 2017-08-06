#include <cstdio>
#include <cmath>
char str[1024];
double parse(const char *str)
{
    bool minus = false;
    bool dot = false;
    int nDot = 0; // digit after dot
    int sum = 0;
    for(int i = 0; str[i]; ++i) {
        if (!minus && str[i] == '-') {
            minus = true;
        } else if (!dot && str[i] == '.') {
            dot = true;
        } else if (str[i] >= '0' && str[i] <= '9') {
            sum *= 10;
            sum += str[i]-'0';
            if (dot) {
                nDot++;
            }
        } else {
            return 1001;
        }
    }
    sum *= (minus ? -1:1);
    if (nDot <= 2) {
        double times[3] = {1, 10, 100};
        double res = sum / times[nDot]; 
        if (res >= -1000 && res <= 1000) {
            return res;
        }
    }
    return 1001;
}
int main()
{
    int n;
    scanf("%d", &n);
    int nValid = 0;
    double sum = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        double res = parse(str);
        if (res == 1001) {
            printf("ERROR: %s is not a legal number\n", str);
        } else {
            sum += res;
            nValid++;
        }
    }
    if (nValid == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (nValid == 1){ // 坑!
        printf("The average of %d number is %.2lf\n", nValid, sum/nValid);
    } else {
        printf("The average of %d numbers is %.2lf\n", nValid, sum/nValid);
    }
    return 0;
}
