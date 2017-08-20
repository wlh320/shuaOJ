#include <cstdio>
#include <vector>
using namespace std;
int w[1001];
int rk[1001];
int main()
{
    int n, nG;
    scanf("%d %d", &n, &nG);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    vector<int> order(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &order[i]);
    }
    int nWin = n;
    vector<int> winner(&order[0], &order[n]);
    while(winner.size() != 1) {
        vector<int> tmp(winner.begin(), winner.end());
        winner.clear();
        nWin = (nWin+nG-1) / nG;
        for(int i = 0; i < nWin; ++i) { // group
            int max = i*nG;
            for(int j = i*nG; j < (i+1)*nG && j < tmp.size(); ++j) {
                if (w[tmp[j]] > w[tmp[max]]) {
                    max = j;
                    rk[tmp[max]] = nWin+1;
                } else {
                    rk[tmp[j]] = nWin+1;
                }
            }
            winner.push_back(tmp[max]);
        }
    }
    rk[winner[0]] = 1;
    for(int i = 0; i < n; ++i) {
        if (i == 0) 
            printf("%d", rk[i]);
        else
            printf(" %d", rk[i]);
    }
    return 0;
}
