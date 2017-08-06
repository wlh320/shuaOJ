#include <cstdio>
int main()
{
    int col;
    char c;
    scanf("%d %c", &col, &c);
    int row = int(col/2.0+0.5);
    for(int i = 0; i < row; ++i) {
        printf("%c", c);
        for(int j = 0; j < col-2; ++j) {
            if (i == 0 || i == row-1) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("%c\n", c);
    }
    return 0;
}
