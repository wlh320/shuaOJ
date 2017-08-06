#include <cstdio>
#include <vector>
using namespace std;
struct Ans
{
    int score;
    int num;
    int answer; // bit
};
Ans ans[100];
int err[100];
int sum[1000];

void parse(int no, int qno)
{
    getchar(); // '('
    int n = getchar() - '0';
    getchar();// ' '
    scanf("%d", &n);
    int myans = 0;
    for(int i = 0; i < n; ++i) {
        char ch;
        ch = getchar();
        getchar();
        myans |= (0x1 << (ch-'a'));
    }
    if (myans == ans[qno].answer) { // right
        sum[no] += ans[qno].score;
    } else {
        err[qno]++;
    }
    getchar(); // ' '
}

int main()
{
    int n, m; 
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int nAns;
        scanf("%d %d %d", &ans[i].score, &ans[i].num, &nAns);
        getchar();
        for(int j = 0; j < nAns; ++j) {
            char ch;
            ch = getchar();
            getchar();
            ans[i].answer |= (0x1 << (ch-'a'));
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            parse(i, j);
        }
        printf("%d\n", sum[i]);
    }
    int max = 0;
    for(int i = 0; i < m; ++i) {
        max = err[i] > max ? err[i]: max;
    }
    if (max == 0) {
        printf("Too simple\n");
    } else {
        printf("%d", max);
        for(int i = 0; i < m; ++i) {
            if (err[i] == max) {
                printf(" %d", i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
