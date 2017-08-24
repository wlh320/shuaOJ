// map的使用和查询, C++的输入输出
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
// title, author, keyword, publisher, year
enum Type {TITLE=0, AUTHOR, KEYWORD, PUB, YEAR};
map<string, vector<string> > q[5];
int main()
{
    int n;
    scanf("%d\n", &n);
    string id, title, author, keyword, pub, year;
    while(n--) {
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        q[TITLE][title].push_back(id);
        q[AUTHOR][author].push_back(id);
        do {
            cin >> keyword;
            q[KEYWORD][keyword].push_back(id);
        } while (getchar()!='\n');
        getline(cin, pub);
        q[PUB][pub].push_back(id);
        getline(cin, year);
        q[YEAR][year].push_back(id);
    }
    map<string, vector<string> >::iterator it;
    for(int i = 0; i < 5; ++i) {
        for(it = q[i].begin(); it != q[i].end(); ++it) {
            sort(it->second.begin(), it->second.end());
        }
    }
    scanf("%d\n", &n);
    int type, len;
    string key;
    while(n--) {
        scanf("%d: ", &type);
        getline(cin, key);
        printf("%d: %s\n", type, key.c_str());
        type--;
        len = q[type][key].size();
        if (len == 0) {
            printf("Not Found\n");
        } else {
            for(int i = 0; i < len; ++i) {
                printf("%s\n", q[type][key][i].c_str());
            }
        }
    }
    return 0;
}
