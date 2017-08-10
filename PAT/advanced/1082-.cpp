// Thank SJ!
#include <cstdio>
#include <cmath>
const char *dstr[10] = {"ling", "yi", "er", "san", "si", 
                         "wu", "liu", "qi", "ba", "jiu"};
const char *wstr[3] = {"Shi", "Bai", "Qian"};

void handle_wan(int n)// 0 <= n < 10000
{
    int digit[4] = {0, 0, 0, 0};
    for(int i = 3; i >= 0; --i) {
        digit[i] = n % 10;
        n /= 10;
    }

    for(int i = 0; i < 3; ++i) {
        if (digit[i] != 0) {
            printf("%s", dstr[digit[i]]);
            printf(" %s ", wstr[2-i]);
        } else if (i > 0 && digit[i-1] != 0) {
            printf("ling ");
        }
        
    }
    if(digit[3] != 0)
        printf("%s", dstr[digit[3]]);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 0) {
        printf("Fu ");
        n = -n;
    }
    if (n / 100000000) {
        printf("%s", dstr[n/100000000]);
        printf("%s", " Yi ");
    }
    if ((n / 10000) % 10000) {
        handle_wan((n / 10000) % 10000);
        printf("%s", " Wan ");
    }
    handle_wan(n % 10000);
    return 0;
}
