#include <cstdio>
struct Stu
{
    char name[11];
    char no[11];
    int score;
};

int main()
{
    int n;
    scanf("%d", &n);
    int min = 0, max = 0;
    Stu *p = new Stu[n];
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %s %d", p[i].name, p[i].no, &p[i].score);
        min = p[i].score < p[min].score ? i:min;
        max = p[i].score > p[max].score ? i:max;
    }
    printf("%s %s\n", p[max].name, p[max].no);
    printf("%s %s\n", p[min].name, p[min].no);
    delete[] p;
    return 0;
}
