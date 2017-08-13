#include <cstdio>
#include <map>
using namespace std;
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int half = row*col/2;
    map<int, int> m;
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            int p;
            scanf("%d", &p);
            m[p] += 1;
            if (m[p] > half) {
                printf("%d\n", p);
                return 0;
            }
        }
    }
    return 0;
}
