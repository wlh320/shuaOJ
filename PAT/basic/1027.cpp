#include <cstdio>
int main()
{
    int n,lvl;
    char ch;
    scanf("%d %c", &n, &ch);
    for(lvl = 0; 2*lvl*lvl-1 <= n; ++lvl);
    lvl -= 1;
    for(int i = lvl; i > 0; --i) {
        int cnt = 2 * i - 1;
        for(int j = 0; j < (lvl-i); ++j)
            printf(" ");
        for(int j = 0; j < cnt; ++j)
            printf("%c", ch);
        // 右边别加空格了就...
        printf("\n");
    }
    for(int i = 2; i <= lvl; ++i) {
        int cnt = 2 * i - 1;
        for(int j = 0; j < (lvl-i); ++j)
            printf(" ");
        for(int j = 0; j < cnt; ++j)
            printf("%c", ch);
        printf("\n");
    }
    printf("%d\n", (n-2*lvl*lvl+1));
    return 0;
}
