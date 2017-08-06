#include <cstdio>
char in[10001];
char map[6] = {'P', 'A', 'T', 'e', 's', 't'};
int cnt[6];
int mapping(char ch)
{
    switch(ch) {
        case 'P':return 0;
        case 'A':return 1;
        case 'T':return 2;
        case 'e':return 3;
        case 's':return 4;
        case 't':return 5;
        default :return -1;
    }
}
int main()
{
    int cntall = 0;
    scanf("%s", in);
    for(int i = 0; in[i]; ++i) {
        int ind = mapping(in[i]);
        if (ind != -1) {
            cnt[ind]++;
            cntall++;
        }
    }
    for(int i = 0; cntall; i = (i+1)%6) {
        if (cnt[i]) {
            printf("%c", map[i]);
            cnt[i]--;
            cntall--;
        }
    }
    return 0;
}
