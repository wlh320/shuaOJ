// thank SJ bcuz of 斗地主
#include <cstdio>
int rank[54];
int res[54];
int tmp[54];
const char color[5] = {'S', 'H', 'C', 'D', 'J'};
void printCard(int no)
{
    int c = no / 13;
    int n = no % 13 + 1;
    printf("%c%d", color[c], n);
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 54; ++i) {
        scanf("%d", &rank[i]);
        rank[i] -= 1;
    }
    for(int i = 0; i < 54; ++i) {
        res[i] = i;
    }
    while(n--) {
        for(int i = 0; i < 54; ++i) {
            tmp[i] = res[i];
        }
        for(int i = 0; i < 54; ++i) {
            res[rank[i]] = tmp[i];
        }
    }
    for(int i = 0; i < 53; ++i) {
        printCard(res[i]);
        putchar(' ');
    }
    printCard(res[53]);
    return 0;
}
