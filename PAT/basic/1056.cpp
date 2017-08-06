#include <cstdio>
int main()
{
   int n;
   int sum = 0;
   scanf("%d", &n); 
   for(int i = 0; i < n; ++i) {
       int tmp;
       scanf("%d", &tmp);
       sum += tmp;
   }
   printf("%d\n", sum*(n-1)*11); // middle school math
   return 0;
}
