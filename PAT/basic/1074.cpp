#include <cstdio>
#include <cstring>
#include <algorithm>
void strrev(char *s)
{
    int l = 0, r = strlen(s)-1;
    while(l<r) {
        std::swap(s[l++], s[r--]);
    }
}
int main()
{
    char base[25];
    scanf("%s", base); strrev(base);
    char a[25], b[25];
    scanf("%s", a); strrev(a);
    scanf("%s", b); strrev(b);
    int len = std::max(strlen(a), strlen(b)) + 1;
    if (strlen(a) < strlen(b)) {
        std::swap(a, b);
    }
    for(int i = strlen(a); i < len; ++i) {
        a[i] = '0';
    }
    for(int i = strlen(b); i < len; ++i) {
        b[i] = '0';
    }
    a[len] = b[len] = '\0';
    int carry = 0;
    int i;
    for(i = 0; i < len; ++i) { // add b to a
        if (base[i] == '0') base[i] += 10;
        int sum = a[i]-'0' + b[i] - '0' + carry;
        carry = sum / (base[i]-'0');
        a[i] = sum % (base[i]-'0') + '0';
    }
    strrev(a);
    bool isLeading = true;
    for(int i = 0; i < strlen(a); ++i) {
        if (a[i] == '0' && !isLeading) {
            putchar(a[i]);
        } else if (a[i] != '0') {
            putchar(a[i]);
            isLeading = false;
        }
    }
    if (isLeading) {
        putchar('0');
    }
    printf("\n");
    return 0;
}
