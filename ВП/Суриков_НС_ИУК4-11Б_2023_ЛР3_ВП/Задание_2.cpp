#include <iostream>
#include <cmath>

/*
Задание 2
Входные данные для проверки:

*/

int main()
{
    int n{};
    double x{}, a{};
    std::cin >> n >> x >> a;
    double p{pow(x + a, 2)};
    for (int i = 0; i < n; i++)
    {
        p = pow(p + a, 2);
    }
    p += a;
    std::cout << p << std::endl;
}
