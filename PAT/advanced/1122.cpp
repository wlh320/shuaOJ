#include <cstdio>
int mat[201][201];
int path[202];
int visit[202];
bool check(int nV)
{
    int n = nV + 1;
    for(int i = 1; i <= nV; ++i) { visit[i]=0;}
    visit[path[0]]++;
    for(int i = 1; i < n; ++i) {
        if (!mat[path[i-1]][path[i]] && !mat[path[i]][path[i-1]]){
            return false;
        }
        visit[path[i]]++;
    }
    if (visit[path[0]] != 2) {
        return false;
    }
    visit[path[0]]--;
    for(int i = 1; i <= nV; ++i) {
        if (visit[i] != 1) {
            return false;
        }
    }
    return true;
}
int main()
{
    int nV, nA;
    int va, vb;
    scanf("%d %d", &nV, &nA);
    for(int i = 0; i < nA; ++i) {
        scanf("%d %d", &va, &vb);
        mat[va][vb] = 1;
        mat[vb][va] = 1;
    }
    int nQ, nL, tmp;
    scanf("%d", &nQ);
    for(int _ = 0; _ < nQ; ++_) {
        scanf("%d", &nL);
        if (nL != nV+1) {
            for(int i = 0; i < nL; ++i) {
                scanf("%d", &tmp);
            }
            printf("NO\n");
        } else {
            for(int i = 0; i < nL; ++i) {
                scanf("%d", &path[i]);
            }
            // 路径都走通且每个节点通过一遍
            if (check(nV)) { 
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
