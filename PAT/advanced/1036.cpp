#include <cstdio>
#include <cstring>
int main()
{
    int n;
    scanf("%d", &n);
    char outM[32] = "Absent";
    char outF[32] = "Absent";
    int minM = 101, maxF = -1;
    for(int i = 0; i < n; ++i) {
        char name[11];
        char id[11];
        int score;
        char gender;
        scanf("%s %c %s %d", name, &gender, id, &score);
        if (gender == 'M' && score < minM) {
            minM = score;
            strcpy(outM, name);
            strcat(outM, " ");
            strcat(outM, id);
        } else if (gender == 'F' && score > maxF) {
            maxF = score;
            strcpy(outF, name);
            strcat(outF, " ");
            strcat(outF, id);
        }
    }
    printf("%s\n%s\n", outF, outM);
    if (minM != 101 && maxF != -1) {
        printf("%d\n", (maxF-minM));
    } else {
        printf("NA\n");
    }
    return 0;
}
