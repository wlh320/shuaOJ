#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int img[1000][1000];
map<int,int> uni;
int main()
{
    int row, col, tol;
    scanf("%d %d %d", &col, &row, &tol);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            scanf("%d", &img[i][j]);
            uni[img[i][j]]++;
        }
    }
    const int di[8] = {-1,-1,-1, 0,0, 1,1,1};
    const int dj[8] = {-1, 0, 1,-1,1,-1,0,1};
    int pi = -1, pj = -1;
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            bool yes = true;
            bool unique = true;
            if (uni[img[i][j]] != 1) {
                unique = false;
            }
            for(int k = 0; k < 8; ++k) {
                int ddi = i+di[k];
                int ddj = j+dj[k];
                if (ddi < 0 || ddi > row || ddj < 0 || ddj > col)
                    continue; // 题目没说清楚边界怎么处理?
                if (std::abs(img[i][j] - img[ddi][ddj]) <= tol) {
                    yes = false;
                    break;
                }
            }
            if (yes && unique) {
                if (pi == -1 && pj == -1) {
                    pi = i;
                    pj = j;
                } else {
                    printf("Not Unique\n");
                    return 0;
                }
            }
        }
    }
    if (pi == -1 && pj == -1) {
        printf("Not Exist\n");
    } else {
        printf("(%d, %d): %d\n", pj+1, pi+1, img[pi][pj]);
    }
    return 0;
}
