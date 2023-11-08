#include <iostream>
#include <cmath>

/*
Задание 2
Входные данные для проверки:
3 1 2
1 1 1
5 10 10
*/

int main()
{
    int n{};
    double x{}, a{};
    std::cin >> n >> x >> a;
    double p{};
    for (int i = 0; i < n; i++)
    {
        p = pow(p + a, 2);
    }
    p += a;
    std::cout << p << std::endl;
}
