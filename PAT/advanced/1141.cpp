// same as B-1085
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct School {
    string name;
    int score;
    int people;
    School(string a, int b, int c)
    {
        name = a;
        score = b;
        people = c;
    }
};
bool cmp(const School& a, const School& b)
{
    if (a.score == b.score) {
        if (a.people == b.people) {
            return a.name < b.name;
        } else {
            return a.people < b.people;
        }
    } else {
        return a.score > b.score;
    }
}
string lower(string& s)
{
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    map<string, double> m;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) { // input and calculate
        string id, school;
        int score;
        cin >> id >> score >> school;
        cnt[lower(school)]++;
        switch (id[0]) {
        case 'B':
            m[lower(school)] += score / 1.5;
            break;
        case 'A':
            m[lower(school)] += score;
            break;
        case 'T':
            m[lower(school)] += score * 1.5;
            break;
        default:
            break;
        }
    }
    vector<School> v;
    for (auto it = m.begin(); it != m.end(); it++) {
        School s(it->first, int(it->second), cnt[it->first]);
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    int rk = 0;
    int pre_score = -1;
    printf("%ld\n", v.size());
    for (unsigned int i = 0; i < v.size(); i++) {
        if (v[i].score != pre_score) {
            rk = i + 1;
        }
        printf("%d %s %d %d\n", rk, v[i].name.c_str(), v[i].score, v[i].people);
        pre_score = v[i].score;
    }
    return 0;
}
