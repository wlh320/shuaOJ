#include <cstdio>
char input[1001];
int cnt[26];
int main()
{
    fgets(input, 1001, stdin);
    for(int i = 0; input[i]; ++i) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            cnt[input[i]-'a']++;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            cnt[input[i]-'A']++;
        }
    }
    int max = 0;
    for(int i = 0; i < 26; ++i) {
        max = cnt[i] > cnt[max] ? i : max;
    }
    printf("%c %d\n", 'a'+max, cnt[max]);
    return 0;
}
