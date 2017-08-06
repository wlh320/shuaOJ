#include <cstdio>
#include <cstring>
#include <cstdlib>
const char *gestr[13] = { "tret",
                           "jan", "feb", "mar", "apr", 
                           "may", "jun", "jly", "aug", 
                           "sep", "oct", "nov", "dec"};
const char *sistr[13] = { "tret",
                           "tam", "hel", "maa", "huh", 
                           "tou", "kes", "hei", "elo", 
                           "syy", "lok", "mer", "jou"};

int main()
{
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; ++i) {
        char input[10];
        fgets(input, 10, stdin);
        for(int i = 10; i > 0; --i) {
            if (input[i] == '\n') {
                input[i] = '\0';
                break;
            }
        }
        if (input[0] >= '0' && input[0] <= '9') { //earth->mars
            int val = atoi(input);
            int si = val / 13;
            int ge = val % 13;
            if (si) {
                printf("%s", sistr[val/13]);
                if (ge != 0)
                    printf(" %s\n", gestr[val % 13]);
                else
                    printf("\n");
            } else
                printf("%s\n", gestr[val % 13]);
        } else { // mars->earth
            int val = 0;
            int j;
            for(j = 0; input[j] && input[j] != ' '; ++j);
            if (input[j] == ' ') {
                input[j++] = '\0';
                for(int k = 0; k < 13; ++k) {
                    if (strcmp(input, sistr[k]) == 0) {
                        val += k * 13;
                        break;
                    }
                }
                
            } else {
                j = 0;
            }
            for(int k = 0; k < 13; ++k) {
                if (strcmp(input+j, sistr[k]) == 0) {
                    val += k * 13;
                    break;
                }
            }
            for(int k = 0; k < 13; ++k) {
                if (strcmp(input+j, gestr[k]) == 0) {
                    val += k;
                    break;
                }
            }
            printf("%d\n", val);
        }
    }

    return 0;
}
