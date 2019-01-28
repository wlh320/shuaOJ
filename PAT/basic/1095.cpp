#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct People {
    string no;
    int score;
    People(string no, int score)
        : no(no)
        , score(score)
    {
    }
    bool operator<(const People& b) const
    {
        if (score == b.score) {
            return no < b.no;
        } else {
            return score > b.score;
        }
    }
};
struct Room {
    int cnt;
    int score;
};
int main()
{
    int n, m;
    map<char, vector<People>> m1;
    map<string, Room> m2;
    map<string, vector<People>> m3; // fake People as Room
    map<string, map<string, int>> m3_helper;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        string no;
        int score;
        cin >> no >> score;

        string room_id = no.substr(1, 3);
        string date = no.substr(4, 6);

        m1[no[0]].push_back(People(no, score)); // for 1
        m2[room_id].cnt += 1; // for 2
        m2[room_id].score += score; // for 2

        m3_helper[date][room_id]++; // for 3
    }

    for (auto p1 = m1.begin(); p1 != m1.end(); p1++) {
        sort(p1->second.begin(), p1->second.end());
    }

    for (auto p3 = m3_helper.begin(); p3 != m3_helper.end(); p3++) {
        string date = p3->first;
        for (auto p = p3->second.begin(); p != p3->second.end(); p++) {
            m3[date].push_back(People(p->first, p->second));
        }
        sort(m3[date].begin(), m3[date].end());
    }

    for (int i = 1; i <= m; i++) {
        int cmd;
        string arg;
        cin >> cmd >> arg;
        printf("Case %d: %d %s\n", i, cmd, arg.c_str());
        switch (cmd) {
        case 1:
            if (m1.find(arg[0]) != m1.end()) {
                auto v = m1[arg[0]];
                for (unsigned int j = 0; j < v.size(); j++) {
                    printf("%s %d\n", v[j].no.c_str(), v[j].score);
                }
            } else {
                printf("NA\n");
            }
            break;
        case 2:
            if (m2.find(arg) != m2.end()) {
                printf("%d %d\n", m2[arg].cnt, m2[arg].score);
            } else {
                printf("NA\n");
            }
            break;
        case 3:
            if (m3.find(arg) != m3.end()) {
                auto v = m3[arg];
                for (unsigned int j = 0; j < v.size(); j++) {
                    printf("%s %d\n", v[j].no.c_str(), v[j].score);
                }
            } else {
                printf("NA\n");
            }
            break;
        }
    }
    return 0;
}