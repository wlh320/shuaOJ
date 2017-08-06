#include <cstdio>
#include <cstring>
char sci[10000];
char res[10000];
int main()
{
    int i,j;
    int z = 0;
    scanf("%s", sci);
    if (sci[0] != '+')
        printf("-");
    for(i=1, j=0; sci[i] != 'E'; ++i) {
        if (sci[i] == '.') continue;
        res[j++] = sci[i];
    }
    i++; // +/-
    int flag = (sci[i++] == '+'? 1:-1);
    for(;sci[i]; ++i) {
        z *= 10;
        z += sci[i] - '0';
    }
    z *= flag;

    if (z < 0) {
        printf("0.");
        for(int i = 0; i < -z-1; ++i)
            printf("0");
        printf("%s\n", res);
    } else {
        if (z >= strlen(res)-1) {
            printf("%s", res);
            for(int i = 0; i < z-strlen(res)+1; ++i)
                printf("0");
        } else {
            for(int i = 0; res[i]; ++i) {
                printf("%c", res[i]);
                if (i == z)
                    printf(".");
            }
        }
    }
    return 0;
}
