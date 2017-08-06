#include <cstdio>
#include <cstring>
char sen[81];

int main()
{
    scanf("%[^\n]", sen);
    int len = strlen(sen);
    int i = len - 1;
    while(i != 0)
    {
        while(sen[i] != ' ' && i != 0){i--;}
        if (i != 0)
            printf("%s ", (sen+i+1));
        else 
            break;
        sen[i] = '\0';
    }
    printf("%s\n", sen);
    return 0;
}
