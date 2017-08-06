#include <cstdio>
char pat[100001];
int tblA[100001];
int main()
{
    int i,j;
    int cntPAT = 0;
    scanf("%s", pat);
    for(i = 0; pat[i] && pat[i] != 'A'; ++i);
    int firstA = i;
    for(i++; pat[i]; ++i){
        if (pat[i] == 'T') tblA[firstA]++;
    }
    int tmpT = 0;
    for(i = firstA+1; pat[i]; ++i) {
        if (pat[i] == 'T') tmpT++;
        if (pat[i] == 'A') tblA[i] = tblA[firstA] - tmpT;
    }

    for(i = 0; pat[i] && pat[i] != 'P'; ++i);
    int firstP = i;
    int firstPcnt = 0;
    for(i++; pat[i]; ++i) {
        if (pat[i] == 'A') firstPcnt = (firstPcnt + tblA[i]) % 1000000007; 
    }
    cntPAT += firstPcnt;
    int tmpA = 0;
    for(i = firstP+1; pat[i]; ++i) {
        if (pat[i] == 'A') {
            tmpA = (tmpA + tblA[i]) % 1000000007;
        }
        if (pat[i] == 'P') {
            cntPAT = (cntPAT + (firstPcnt - tmpA)) % 1000000007;
        }
    }
    printf("%d\n", cntPAT);
    return 0;
}
