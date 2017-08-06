#include <cstdio>
#include <cstring>
const char poker[3] = {'J', 'Q', 'K'};
int main()
{
    char a[101];
    char b[101];
    char c[101] = {0};
    scanf("%s %s", a, b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    int i = lenB - 1;
    int j = lenA - 1;
    int k = lenB > lenA ? i:j;
    for(; j >= 0 || i >= 0; i--, j--, k--) {
        int aj = j >= 0 ? a[j] : '0';
        int bi = i >= 0 ? b[i] : '0';
        if ((lenB-i) % 2 != 0) {
            char sum = (bi+aj-'0'-'0') % 13;
            sum = sum < 10 ? sum + '0' : poker[sum%10];
            c[k] = sum; 
        } else {
            int tmp = bi - aj;
            tmp = tmp < 0 ? tmp+10 : tmp;
            c[k] = tmp + '0';
        }
    }
    printf("%s\n", c);
    return 0;
}
