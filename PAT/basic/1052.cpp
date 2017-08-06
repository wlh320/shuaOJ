#include <cstdio>
char paws[10][5];
char mous[10][5];
char eyes[10][5];

int split(char dest[][5]) 
{
    int count = 0, k = 0;
    char ch;
    bool flag = false;
    while((ch = getchar()) != '\n') {
        if (flag && ch == ']') {
            dest[count][k] = '\0';
            flag = false;
            count++;
        } else if (flag) {
            dest[count][k++] = ch;
        } else if (ch == '[') {
            flag = true;
            k = 0;
        }
    }
    return count;
}

int main()
{
    int n_p = split(paws);
    int n_e = split(eyes);
    int n_m = split(mous);
    int n;
    scanf("%d", &n);
    while(n--) {
        int p1, e1, m, e2, p2;
        scanf("%d %d %d %d %d\n", &p1, &e1, &m, &e2, &p2);
        if (p1 > n_p || p2 > n_p || e1 > n_e || e2 > n_e || m > n_m ||
            p1 < 1 || e1 < 1 || m < 1 || e2 < 1 || p2 < 1) { // 忘了小于1了
            printf("Are you kidding me? @\\/@\n");
        } else {
            printf("%s(%s%s%s)%s\n", 
                   paws[p1-1], eyes[e1-1], mous[m-1], eyes[e2-1], paws[p2-1]);
        }
    }
    return 0;
}
