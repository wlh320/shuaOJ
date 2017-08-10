#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Stud
{
    int id;
    char name[9];
    int grade; 
};
int c;
Stud s[100000];

bool cmp(Stud a, Stud b)
{
    switch(c) {
        case 1 : return a.id < b.id;
        case 2 : return strcmp(a.name, b.name) <= 0;
        case 3 : return a.grade <= b.grade;
        default: return false;
    }
}

int main()
{
    int n;
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s %d", &s[i].id, s[i].name, &s[i].grade);
    }
    sort(s, s+n, cmp);
    for(int i = 0; i < n; ++i) {
        printf("%06d %s %d\n", s[i].id, s[i].name, s[i].grade);
    }
    return 0;
}
