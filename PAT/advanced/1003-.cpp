#include <cstdio>
int wVex[500];
int arc[500][500];
int main()
{
    int nVex, nArc;
    int from, to;
    scanf("%d %d %d %d", &nVex, &nArc, &from, &to);
    for(int i = 0; i < nVex; ++i) {
        scanf("%d", &wVex[i]);
    }
    for(int i = 0; i < nArc; ++i) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        arc[start][end] = weight;
    }
    return 0;
}
