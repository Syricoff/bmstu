#include <cmath>
#include <iostream>

/*
Задание 1
Входные данные для проверки:

*/

int main()
{
    double e{0.012};
    double a1{}, a2{};
    int n{1};
    double sum{a1};
    do
    {
        a1 = (2 * n) / std::pow((2 + n), 2) * (1 / std::pow((n + 1), 2));
        sum += a1;
        n++;
        a2 = (2 * n) / std::pow((2 + n), 2) * 1 / std::pow((n + 1), 2);
        std::cout << sum << " " << a1 << " " << a2 << " " << (a1 - a2) << " " << (a1 - a2) <= e << std::endl;
    } while ((std::fabs(a1 - a2)) <= e);
    std::cout << sum << " " << a1 << " " << a2 << std::endl;
}
