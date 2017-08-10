// wtf?根本不值20分,顶多5分
#include <cstdio>
int main()
{
    int r, g, b;
    const char *ch = "0123456789ABC";
    scanf("%d %d %d", &r, &g, &b);
    printf("#%c%c%c%c%c%c\n", 
    ch[r/13], ch[r%13], ch[g/13], ch[g%13], ch[b/13], ch[b%13]);
    return 0;
}
