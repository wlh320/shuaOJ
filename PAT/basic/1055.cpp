#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Person
{
    char name[9];
    int height; 
};
Person p[10001];

bool cmp(Person a, Person b)
{
    if (a.height != b.height) {
        return a.height > b.height;
    } else {
        return strcmp(a.name, b.name) < 0;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%s %d", p[i].name, &p[i].height); 
    }
    sort(p, p+n, cmp);
    int begin = 0;
    for(int i = 0; i < k; ++i) {
        int ppl = (i == 0 ? n/k+n%k : n/k);
        int mid = ppl / 2;
        for(int j = 0; j < ppl; ++j) {
            const char *format = j == 0? "%s": " %s";
            int cha = j - mid;
            if (cha < 0 ) {
                cha = -cha;
                printf(format, p[begin+2*cha-1].name);
            } else {
                printf(format, p[begin+2*cha].name);
            }
        }
        begin += ppl;
        printf("\n");
    }
    return 0;
}
