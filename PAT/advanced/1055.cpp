#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Man
{
    char name[9];
    int age;
    int worth;
};

bool cmp(Man a, Man b)
{
    if (a.worth != b.worth) {
        return a.worth > b.worth;
    } else {
        if (a.age != b.age) {
            return a.age < b.age;
        } else {
            return strcmp(a.name, b.name) < 0;
        }
    }
}

Man m[100000];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%s %d %d", m[i].name, &m[i].age, &m[i].worth);
    }
    sort(m, m+n, cmp);
    int np, ageS, ageE;
    for(int i = 1; i <= k; ++i) {
        int cnt = 0;
        printf("Case #%d:\n", i);
        scanf("%d %d %d", &np, &ageS, &ageE);
        for(int j = 0; j < n; ++j) {
            if (m[j].age >= ageS && m[j].age <= ageE) {
                printf("%s %d %d\n", m[j].name, m[j].age, m[j].worth);
                cnt++;
            }
            if (cnt == np) {
                break;
            }
        }
        if (cnt == 0) {
            printf("None\n");
        }
    }
    return 0;
}
