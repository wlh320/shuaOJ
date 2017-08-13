// Thank SJ!
#include <cstdio>
#include <cmath>
const char *dstr[10] = {"ling", "yi", "er", "san", "si", 
                         "wu", "liu", "qi", "ba", "jiu"};
const char *wstr[8] = {"Yi","Qian","Bai","Shi","Wan","Qian", "Bai", "Shi"};

int main()
{
    int n;
    int digit[9];
    bool first = true;
    scanf("%d", &n);
    if (n == 0) {
        printf("ling");
        return 0;
    }
    if (n < 0) {
        printf("Fu ");
        n = -n;
    }
    int tmp = n;
    for(int i = 8; i >= 0; --i) {
        digit[i] = tmp % 10;
        tmp /= 10;
    }
    for(int i = 0; i < 9; ++i) {
        const char *format = first?"%s":" %s";
        if (digit[i]) {
            printf(format, dstr[digit[i]]);
            first = false;
            if (i != 8) {
                printf(" %s", wstr[i]);
            }
        } else {
            if (i == 4 && n >= 10000 && n < 100000000) {
                printf(" %s", wstr[4]);
            }
            if ( i != 8 && digit[i+1] != 0 && n > pow(10, 9-i)) {
                printf(" ling");
            }
        }
    }
    return 0;
}
