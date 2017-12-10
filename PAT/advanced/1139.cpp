// 这次题比以前简单太多, 这么暴力都能过
// 神TM "-0000"
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;
map<int, bool> gender;
map<int, vector<int>> homo;
map<int, map<int, bool>> conn;

int str2int(const char* str, bool update = true)
{
    int l = strlen(str);
    int res = 0;
    if (l == 4) {
        res = 1000 * (str[0] - '0') + 100 * (str[1] - '0') + 10 * (str[2] - '0') + str[3] - '0';
        if (update) {
            gender[res] = false;
        }
    } else if (str[0] == '-') {
        res = 1000 * (str[1] - '0') + 100 * (str[2] - '0') + 10 * (str[3] - '0') + str[4] - '0';
        if (update) {
            gender[res] = true;
        }
    }
    return res;
}

void findConn(int a, int b)
{
    int cnt = 0;
    vector<pair<int, int>> ans;
    set<int> afriend;
    set<int> bfriend;
    for (int i = 0; i < homo[a].size(); ++i) {
        if (homo[a][i] != b)
            afriend.insert(homo[a][i]);
    }
    for (int i = 0; i < homo[b].size(); ++i) {
        if (homo[b][i] != a)
            bfriend.insert(homo[b][i]);
    }
    set<int>::iterator ap = afriend.begin();
    for (; ap != afriend.end(); ++ap) {
        set<int>::iterator bp = bfriend.begin();
        for (; bp != bfriend.end(); ++bp) {
            if (conn[*ap][*bp]) {
                cnt++;
                ans.push_back(make_pair(*ap, *bp));
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%04d %04d\n", ans[i].first, ans[i].second);
    }
}
int main()
{
    int n_vex, n_arc, n_query;
    scanf("%d %d", &n_vex, &n_arc);
    for (int i = 0; i < n_arc; ++i) {
        int a, b;
        char sa[8], sb[8];
        scanf("%s %s", sa, sb);
        a = str2int(sa);
        b = str2int(sb);
        conn[a][b] = true;
        conn[b][a] = true;
        if (gender[a] == gender[b]) {
            homo[a].push_back(b);
            homo[b].push_back(a);
        }
    }
    scanf("%d", &n_query);
    for (int i = 0; i < n_query; ++i) {
        int a, b;
        char sa[8], sb[8];
        scanf("%s %s", sa, sb);
        a = str2int(sa, false);
        b = str2int(sb, false);
        findConn(a, b);
    }
    return 0;
}
