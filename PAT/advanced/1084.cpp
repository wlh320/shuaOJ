// same as B-1029
#include <cstdio>
bool checked[256];
char expected[81];
char real[81];
int main()
{
    scanf("%s", expected);
    scanf("%s", real);

    char *pe = expected;
    char *pr = real;

    for (int i = 0; expected[i]; ++i)
        if(expected[i] >= 'a' && expected[i] <= 'z')
            expected[i] += ('A'-'a');
    for (int i = 0; real[i]; ++i)
        if(real[i] >= 'a' && real[i] <= 'z')
            real[i] += ('A'-'a');

    while(*pe && *pr) {
        while(*pe != *pr && *pe && *pr) {
            if (!checked[*pe]) {
                printf("%c", *pe);
                checked[*pe] = true;
            }
            pe++;
        }
        while(*pe == *pr && *pe && *pr) {
            pe++;
            pr++;
        }
    }
    if (*pe) {
        while(*pe) {
            if (!checked[*pe]) {
                printf("%c", *pe);
                checked[*pe] = true;
            }
            pe++;
        }
    }
    return 0;
}
