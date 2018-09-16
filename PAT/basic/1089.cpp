#include <cstdio>
int n;
int vote[105];
bool isValid(int w1, int w2)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vote[i] < 0) {
            cnt++;
            if (cnt > 2) {
                return false;
            }
            if (vote[i] != -w1 && vote[i] != -w2) {
                return false;
            }
        }
        if (vote[i] == w1 || vote[i] == w2) {
            return false;
        }
    }
    return true;
}
bool solve(int w1, int w2, int lier1)
{
    int lier2;
    for (lier2 = 1; lier2 <= n; lier2++) {
        if (lier2 == w1 || lier2 == w2) continue;
        vote[lier1] = -vote[lier1];
        vote[lier2] = -vote[lier2];
        if (isValid(w1, w2)) {
            printf("%d %d\n", w1, w2);
            return true;
        }
        vote[lier1] = -vote[lier1];
        vote[lier2] = -vote[lier2];
    }
    return false;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &vote[i]);
    }
    int w1, w2;
    for (w1 = 1; w1 <= n; w1++) {
        for (w2 = w1 + 1; w2 <= n; w2++) {
            bool yes = solve(w1, w2, w1);
            if (!yes) {
                yes = solve(w1, w2, w2);
            }
            if (yes) return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
