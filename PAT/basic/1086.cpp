// 狗屎题，也没说倒着不能0开头啊？
#include <cstdio>
#include <iostream>
int main()
{
    int a, b;
    std::cin >> a >> b;
    int m = a * b;
    bool flag = true;
    while (m) {
        if (m % 10) {
            flag = false;
        }
        if (!flag || m % 10 != 0)
            printf("%d", m % 10);
        m /= 10;
    }
    printf("\n");
    return 0;
}
