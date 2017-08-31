// 记住小数点位置和有效位数, 类似科学计数法表示
#include <cstdio>
#include <cstring>
#define MAX 200
struct Sci
{
    char s[MAX]; // string
    int e; // 10^e
};

Sci scientific(const char *s, int n)
{
    Sci res;
    int fstPos = -1, dotPos = -1;
    int idx = 0, i = 0;
    for(i = 0; s[i]; ++i) {
        if (s[i] == '.') {
            dotPos = i;
            continue;
        }
        if (s[i] == '0' && fstPos == -1) continue; // 前导零
        if (s[i] != '0' && fstPos == -1) { // 第一个有效位
            fstPos = i;
        }
        if (idx < n) {
            res.s[idx++] = s[i];
        }
    }
    res.s[idx] = '\0';
    if (dotPos == -1) { // 整数
        dotPos = i;
    }
    res.e = dotPos < fstPos ? dotPos-fstPos+1 : dotPos-fstPos;
    if (idx == 0) { // 0
        int j;
        for(j = 0; j < n; ++j) {
            res.s[j] = '0';
        }
        res.s[j] = '\0';
        res.e = 0;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    char d1[MAX];
    char d2[MAX];
    scanf("%s %s", d1, d2);
    Sci s1 = scientific(d1, n);
    Sci s2 = scientific(d2, n);
    if (!strcmp(s1.s, s2.s)) {
        printf("YES 0.%s*10^%d\n", s1.s, s1.e);
    } else {
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", s1.s, s1.e, s2.s, s2.e);
    }
    return 0;
}
