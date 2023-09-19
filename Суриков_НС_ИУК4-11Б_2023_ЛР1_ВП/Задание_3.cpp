#include <iostream>
#include <cmath>

/*
Задание 3
Входные данные для проверки:

*/

int main()
{
    double x{}, y{};
    std::cin >> x >> y;
    double d = (pow(sin(x), 2) + cos(x)) / (x + pow(y, 4) * exp(fabs(x - y)));
    double fract_part{}, int_part{};
    fract_part = std::modf(std::fabs(d), &int_part);
    int sum = int(fract_part * 10) % 10 +
              int(fract_part * 100) % 10 +
              int(fract_part * 1000) % 10;
    std::cout << d << '\n'
              << fract_part << '\n'
              << sum << std::endl;
}
