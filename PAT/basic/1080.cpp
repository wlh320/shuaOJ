#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Student {
    string name;
    int oj;
    int mid;
    int end;
    int score;
    Student(string s, int a)
    {
        name = s;
        oj = a;
        mid = -1;
        end = -1;
        score = 0;
    }
    Student() {}
};
bool cmp(const Student& a, const Student& b)
{
    if (a.score == b.score) {
        return a.name < b.name;
    } else {
        return a.score > b.score;
    }
}
int main()
{
    map<string, Student> m;
    vector<Student> s;
    int n_stu, n_mid, n_end;
    scanf("%d %d %d", &n_stu, &n_mid, &n_end);

    char name[32];
    int s_oj, s_mid, s_end;
    for (int i = 0; i < n_stu; ++i) {
        scanf("%s %d", name, &s_oj);
        Student s(name, s_oj);
        m[name] = s;
    }

    for (int i = 0; i < n_mid; ++i) {
        scanf("%s %d", name, &s_mid);
        if (m.find(name) != m.end()) {
            m[name].mid = s_mid;
        }
    }

    for (int i = 0; i < n_end; ++i) {
        scanf("%s %d", name, &s_end);
        if (m.find(name) != m.end()) {
            m[name].end = s_end;
        }
    }

    map<string, Student>::iterator it = m.begin();
    for (; it != m.end(); it++) {
        Student ss = it->second;
        if (ss.oj >= 200) {
            if (ss.mid > ss.end) {
                int tmp = (ss.end == -1 ? 0 : ss.end);
                ss.score = int(ss.mid * 0.4 + tmp * 0.6 + 0.5);
            } else {
                ss.score = ss.end;
            }
            if (ss.score >= 60)
                s.push_back(ss);
        }
    }
    sort(s.begin(), s.end(), cmp);
    for (unsigned int i = 0; i < s.size(); ++i) {
        printf("%s %d %d %d %d\n", s[i].name.c_str(), s[i].oj, s[i].mid, s[i].end, s[i].score);
    }
    return 0;
}
