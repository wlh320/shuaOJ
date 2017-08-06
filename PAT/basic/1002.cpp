#include <cstdio>
#include <cstring>
const char* trans[10] = {"ling","yi", "er", "san", "si", "wu", 
"liu", "qi", "ba", "jiu"};

int sum_arr[3];

int main()
{
    int sum = 0;
    char num[101];
    scanf("%s", num);
    for(int i = 0; num[i]; ++i)
        sum += (num[i] - '0');
    
    sum_arr[0] = sum / 100;
    sum %= 100;
    sum_arr[1] = sum / 10;
    sum %= 10;
    sum_arr[2] = sum;

    if (sum_arr[0])
        printf("%s ", trans[sum_arr[0]]);
    if (sum_arr[1] || sum_arr[0])
        printf("%s ", trans[sum_arr[1]]);
    printf("%s\n", trans[sum_arr[2]]);
    return 0;
}
