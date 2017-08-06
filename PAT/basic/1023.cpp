#include <cstdio>
int main()
{
    int cnt[10];
    int i;
    for(i = 0; i < 10; ++i)
        scanf("%d", &cnt[i]);
    
    for(i = 1; !cnt[i]; ++i); // find cnt[i]!=0
    printf("%d", i);
    if (cnt[0])
        for(int j = 0; j < cnt[0]; ++j)
            printf("0");

    for(int j = 0; j < cnt[i]-1; ++j)
        printf("%d", i);
    
    for(i += 1; i < 10; ++i) {
        if (cnt[i])
            for(int j = 0; j < cnt[i]; ++j)
                printf("%d", i);
    }
    return 0;
}
