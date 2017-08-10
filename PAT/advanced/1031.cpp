#include <cstdio>
#include <cstring>
int main()
{
    int n1, n2, n3;
    char str[81];
    scanf("%s", str);
    int len = strlen(str) + 2;
    n1 = n3 = len/3;
    n2 = len/3 + len%3;
    int head = 0, tail = len - 3;
    for(int i = 0; i < n1; ++i) {
        if(i != n1-1) {
            putchar(str[head++]);
            for(int j = 0; j < n2-2; ++j)
                putchar(' ');
            putchar(str[tail--]);
            putchar('\n');
        } else {
            for(int j = head; j <= tail; ++j) {
                putchar(str[j]);
            }   
            putchar('\n');
        }
    }
    return 0;
}
