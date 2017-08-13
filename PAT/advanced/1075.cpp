#include <cstdio>
#include <algorithm>
using namespace std;
struct User
{
    int id;
    int nPass;
    int score[5];
    bool show;
    int total;
};
User u[10000];
int acScore[5];
bool cmp(User a, User b)
{
    if (a.total != b.total) {
        return a.total > b.total;
    } else {
        if (a.nPass != b.nPass) {
            return a.nPass > b.nPass;
        } else {
            return a.id < b.id;
        }
    }
}
int main()
{
    int n,k,m; // n-user k-problem m-submission
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < n; ++i) { // init;
        u[i].id = i+1;
        u[i].show = false;
        for(int j = 0; j < k; ++j) {
            u[i].score[j] = -1;
        }
        u[i].total = 0;
        u[i].nPass = 0;
    }
    for(int i = 0; i < k; ++i) {
        scanf("%d", &acScore[i]);
    }
    for(int i = 0; i < m; ++i) {
        int no, pro, s;
        scanf("%d %d %d", &no, &pro, &s);
        no--;pro--;
        if (s != -1) {
            u[no].show = true;
        } else {
             if (u[no].score[pro] == -1) {
                 u[no].score[pro] = 0;
             }
        }
        if (s > u[no].score[pro]) {
            if (s == acScore[pro]) {
                u[no].nPass++;
            }
            if (u[no].score[pro] == -1) {
                u[no].total += s;
            } else {
                u[no].total += (s - u[no].score[pro]);
            }
            u[no].score[pro] = s;
        }
    }
    sort(u, u+n, cmp);
    int rank = 1;
    int pre = 1;
    int preTotal = 0;
    for(int i = 0; i < n; ++i) {

        if (u[i].show) {
            int trank = (u[i].total == preTotal)? pre:rank;
            printf("%d %05d %d", trank, u[i].id, u[i].total);
            for(int j = 0; j < k; ++j) {
                printf(" ");
                if (u[i].score[j] == -1) {
                    printf("-");
                } else {
                    printf("%d", u[i].score[j]);
                }
            }
            rank++;
            pre = trank;
            preTotal = u[i].total;
            printf("\n");
        }
    }
    return 0;
}
