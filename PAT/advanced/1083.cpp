#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
    char name[11];
    char id[11];
    int grade;
};
bool cmp(Student a, Student b)
{
    return a.grade > b.grade;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<Student> s(n);
    for(int i = 0; i < n; ++i) {
        scanf("%s %s %d", s[i].name, s[i].id, &s[i].grade);
    }
    int min, max;
    scanf("%d %d", &min, &max);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if (s[i].grade >= min && s[i].grade <= max) {
            cnt++;
        } else {
            s[i].grade = -100;
        }
    }
    sort(s.begin(), s.end(), cmp);
    if (cnt == 0) {
        printf("NONE\n");
    } else {
        for(int i = 0; i < cnt; ++i) {
            printf("%s %s\n", s[i].name, s[i].id);
        }
    }
    return 0;
}
