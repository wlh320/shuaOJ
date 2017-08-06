#include <cstdio>
#include <cstring>

const char* week[] = {NULL, "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

bool isWeek(char ch) // A-G
{
    return ch >= 'A' && ch <= 'G';
}

bool isCap(char ch) // A-N
{
    return ch >= 'A' && ch <= 'N';
}

bool isDigit(char ch)// 0-9
{
    return ch >= '0' && ch <= '9';
}

bool isLetter(char ch) // a-z A-Z
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
}

int main()
{
    int stage = 1;
    char str[4][61];

    for(int i = 0; i < 4; ++i)
        scanf("%s", str[i]);
    
    for(int i = 0;str[0][i] && str[1][i];++i)
    {
        if(stage == 1 && isWeek(str[0][i]) && str[0][i] == str[1][i]) {
            stage = 2;
            printf("%s ", week[str[0][i]-'A'+1]);
        }
        else if (stage == 2 && isCap(str[0][i]) && str[0][i] == str[1][i]) {
            printf("%02d:", str[0][i]-'A'+10);
            break;
        }
        else if (stage == 2 && isDigit(str[0][i]) && str[0][i] == str[1][i]) {
            printf("%02d:", str[0][i]-'0');
            break;
        }
    }
    for(int i = 0;str[2][i] && str[3][i]; ++i)
    {
        if(isLetter(str[2][i]) && str[2][i] == str[3][i]) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}
