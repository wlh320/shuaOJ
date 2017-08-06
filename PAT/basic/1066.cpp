#include <cstdio>

int main()
{
    int row, col, l, r, k; //
    scanf ("%d %d %d %d %d", &row, &col, &l, &r, &k);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            int p;
            scanf("%d", &p);
            if (p < l || p > r) {
                if (j == 0)
                    printf("%03d", p);
                else
                    printf(" %03d", p);
            } else {
                if(j == 0) 
                    printf("%03d", k);
                else
                    printf(" %03d", k);
            }
        }
        printf("\n");
    }
    return 0;
}
