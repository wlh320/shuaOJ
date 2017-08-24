// 并查集分成若干家庭,记录每个家庭的最小id,然后计算每个家庭的平均值
#include <cstdio>
#include <algorithm>
struct Man
{
    int n; // n members
    int est, area;
    Man(){n = 1;}
};
Man m[10001];
int uset[10001];
bool visit[10001];
int fam[1001];
bool cmp(int a, int b)
{
    double sa = double(m[a].area) / m[a].n;
    double sb = double(m[b].area) / m[b].n;
    if (sa != sb) {
        return sa > sb;
    } else {
        return a < b;
    }
}
int find(int x)
{
    int pre = x;
    while(uset[pre] != pre) pre = uset[pre];
    int p = x, tmp;
    while(p != pre) {
        tmp = uset[p];
        uset[p] = pre;
        p = tmp;
    }
    return pre;
}
void join(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x > y) std::swap(x, y);
    if (x != y) { // x < y
        uset[y] = x;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int id, ba, ma, k, ch;
    for(int i = 0; i < 10000; ++i) uset[i] = i; 
    while(n--) {
        scanf("%d %d %d", &id, &ba, &ma);
        visit[id] = true;
        if (ba != -1) { join(id, ba); visit[ba] = true;}
        if (ma != -1) { join(id, ma); visit[ma] = true;}
        if (ba != -1 && ma != -1) { join(ba, ma); }
        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d", &ch);
            join(id, ch);
            visit[ch] = true;
        }
        scanf("%d %d", &m[id].est, &m[id].area);
    }
    int r;
    int cnt = 0;
    for(int i = 0; i < 10000; ++i) {
        if (visit[i] && uset[i] != i) {
            r = uset[i];
            if (uset[r] != r) { r = find(r); }
            m[r].n += 1;
            m[r].area += m[i].area;
            m[r].est += m[i].est;
            visit[i] = false; 
        }
        if (visit[i] && uset[i] == i) {
            fam[cnt] = i;
            cnt++;
        }
    }
    std::sort(fam, fam+cnt, cmp);
    double avgSet, avgArea;
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; ++i) {
        id = fam[i];
        avgSet = double(m[id].est) / m[id].n;
        avgArea = double(m[id].area) / m[id].n;
        printf("%04d %d %.3lf %.3lf\n", id, m[id].n, avgSet, avgArea);
    }
    return 0;
}
