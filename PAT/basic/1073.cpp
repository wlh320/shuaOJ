#include <cstdio>
bool ans[100][5];
int errCnt[100][5];
int score[100];
double stuScore[1001];
void handleOne(int stuID, int qID)
{
    bool option[5]={0,0,0,0,0};
    getchar(); // '('
    int n = getchar() - '0';
    for(int i = 0; i < n; ++i) {
        getchar();
        int op = getchar() - 'a';
        option[op] = true;
    }
    getchar(); // ')'

    // check
    bool right = true;
    bool error = false;
    for(int i = 0; i < 5; ++i) {
        if (option[i] && !ans[qID][i]) { // 多选了
            right = false;
            error = true;
            errCnt[qID][i]++;
        } else if (!option[i] && ans[qID][i]) {
            right = false;
            errCnt[qID][i]++;
        }
    }
    if (right) {
        stuScore[stuID] += score[qID];
    } else if (!error) {
        stuScore[stuID] += score[qID] / 2.0;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int nOp, nAns;
        scanf("%d %d %d", &score[i], &nOp, &nAns);
        getchar();
        for(int j = 0; j < nAns; ++j) {
            char ch = getchar();
            ans[i][ch-'a'] = true;
            getchar();
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            handleOne(i, j);
            getchar();
        }
        printf("%.1lf\n", stuScore[i]);
    }
    int max = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < 5; ++j) {
            if (errCnt[i][j] > max) {
                max = errCnt[i][j];
            }
        }
    }
    if (max == 0) {
        printf("Too simple\n");
        return 0;
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < 5; ++j) {
            if (errCnt[i][j] == max) {
                printf("%d %d-%c\n",max, i+1, 'a'+j);
            }
        }
    }
    return 0;
}
