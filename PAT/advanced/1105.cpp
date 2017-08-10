// same as B-1050
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int num[10000];
int mat[10000][10000];
bool cmp(int a, int b) {return a >= b;}
int main()
{
    int N;
    scanf("%d",&N);
    int m = N,n = 1;
    for(int i = sqrt(N); i < N; ++i) {
        if (N % i == 0) {
            m = i;
            n = N / m;
            if (m < n)
                swap(m , n);
            break;
        }
    }
    for(int i = 0; i < N; ++i)
        scanf("%d", &num[i]);
    sort(num, num+N, cmp);
    
    int i = 0, j = 0;
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    int d = 0;
    for(int k = 0; k < N; ++k) {
        mat[i][j] = num[k];
        if (j+dj[d] > n-1 || j+dj[d] < 0 || 
            i+di[d] > m-1 || i+di[d] < 0 || mat[i+di[d]][j+dj[d]] != 0) {
            d = (d + 1) % 4;
        }
        i += di[d];
        j += dj[d];
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if (j == 0) {
                printf("%d", mat[i][j]);
            } else {
                printf(" %d", mat[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

