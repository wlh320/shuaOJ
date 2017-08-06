#include <cstdio>
#define C 0
#define J 1
#define B 2
int win[2][3];
void handle_cjb(char a, char b)
{
    if (a == b) return ;
    switch(a) {
        case 'C':
            if (b == 'J') win[0][C]++;  
            else win[1][B]++;
            break;
        case 'J':
            if (b == 'B') win[0][J]++;
            else win[1][C]++;
            break;
        case 'B':
            if (b == 'C') win[0][B]++;
            else win[1][J]++;
            break;
    }
}
inline char most(int i)
{
    return win[i][B] >= win[i][C] ? (win[i][B] >= win[i][J]?'B':'J'):
                                    (win[i][C] >= win[i][J]?'C':'J');
}
int main()
{
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; ++i) {
        char a, b;
        scanf("%c %c ", &a, &b);
        handle_cjb(a, b);
    }
    int awin = win[0][C] + win[0][J] + win[0][B];
    int bwin = win[1][C] + win[1][J] + win[1][B];
    printf("%d %d %d\n", awin, n-(awin+bwin), bwin);
    printf("%d %d %d\n", bwin, n-(awin+bwin), awin);
    printf("%c %c\n", most(0), most(1));
    return 0;
}
