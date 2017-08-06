#include <cstdio>
bool check(char in[])
{
    int stage = 0;
    int sum_a[3] = {0,0,0};
    for(int i = 0; in[i]; ++i)
    {
        if (in[i] != 'P' && in[i] != 'A' && in[i] != 'T') {
            return false;
        }        
        else if (in[i] == 'P') {
            if (stage != 0) return false;
            stage = 1;
        }
        else if (in[i] == 'T') {
            if (stage != 1) return false;
            stage = 2;
        }
        else if (in[i] == 'A')
            sum_a[stage]++; 
    }
    if (stage != 2 || sum_a[1] == 0 || sum_a[2] != sum_a[1] * sum_a[0])
        return false;
    return true;
}
int main()
{
    int n;
    char in[101];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", in);
        if (check(in))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
