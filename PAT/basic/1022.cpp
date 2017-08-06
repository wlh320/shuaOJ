#include <cstdio>
#include <stack>
using namespace std;
void ten2d(int n, int d)
{
    stack<int> s;
    if (n == 0) {
        printf("0");
        return ;
    }
    while(n != 0)
    {
        s.push(n % d);
        n /= d;
    }
    while(!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }
}
int main()
{
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    ten2d(a+b, d);
}
