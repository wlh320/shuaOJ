#include <cstdio>
#include <cstring>
char suffix[257];
char str[257];
int main()
{
    int n, min = -1;
    scanf("%d\n", &n);
    char *ps, *pt;
    gets(suffix); // ??? 到底怎么读带空格字符串啊
    for(int _ = 0; _ < n-1; ++_) {
        gets(str);
        ps = suffix + strlen(suffix)-1;
        pt = str + strlen(str)-1;
        while(*pt-- == *ps--);
        min = (ps-suffix+1) > min ? (ps-suffix+1):min;
    }
    if (min == strlen(suffix)-1) {
        printf("nai\n");
    } else {
        printf("%s", suffix+min+1);
    }
    return 0;
}
