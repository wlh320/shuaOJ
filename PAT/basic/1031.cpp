#include <cstdio>
int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char table[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main()
{
    int n;
    scanf("%d", &n);
    bool wrong = false;
    for(int _ = 0; _ < n; ++_) {
        char id[19];
        scanf("%s", id);
        int sum = 0, i = 0;
        for(i = 0; i < 17; ++i) {
            if (!(id[i] >= '0' && id[i] <= '9')) {
                printf("%s\n", id);
                wrong = true;
                break;
            } else {
                sum += (id[i]-'0')*weight[i];
            }
        }
        if (i >= 17) {
            if (id[17] != table[sum%11]) {
                printf("%s\n", id);
                wrong = true;
            }
        }
    }
    if (!wrong)
        printf("All passed\n");
    return 0;
}
