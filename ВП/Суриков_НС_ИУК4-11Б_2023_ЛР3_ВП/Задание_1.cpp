#include <cmath>
#include <iostream>

/*
Задание 1
Входные данные для проверки:

*/

int main()
{
    double e{0.012};
    int n{1};
    double a1{}, a2{};
    double sum{};
    do
    {
        a1 = a2;
        sum += a1;
        a2 = (2 * n) / std::pow((2 + n), 2) * (1 / std::pow((n + 1), 2));
        n++;
    } while (std::fabs(a1 - a2) >= e);
    std::cout << sum << std::endl;
}
