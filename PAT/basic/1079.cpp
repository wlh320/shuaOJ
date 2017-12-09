#include <cstdio>
#include <cstring>
unsigned int len = 0;
char num[10240];
char rev[10240];
bool isPalin(const char* str)
{
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

// reverse rev -> num
// calculate on rev
void reverse(char* dest, char* src)
{
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        dest[len - i - 1] = src[i];
    }
}
int main()
{
    scanf("%s", num);
    reverse(rev, num);
    int i;
    for (i = 0; i < 10; ++i) {
        if (isPalin(rev)) {
            break;
        }
        printf("%s + %s = ", num, rev);
        // calculate
        int carry = 0;
        int len = strlen(rev);
        int j;
        for (j = 0; j < len; ++j) {
            int sum = (rev[j] - '0') + (num[j] - '0') + carry;
            rev[j] = (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry) {
            rev[j] = carry + '0';
        }
        reverse(num, rev);
        printf("%s\n", num);
    }
    if (i < 10) {
        printf("%s is a palindromic number.\n", rev);
    } else {
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}
