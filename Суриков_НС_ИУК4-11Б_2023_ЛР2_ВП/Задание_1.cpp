#include <cmath>
#include <iomanip>
#include <iostream>

/*
Задание 1
Входные данные для проверки:
*/

int main()
{
    double a{}, y{};
    std::cin >> a;
    if (a < 0)
    {
        y = -a;
    }
    else if (0 < a < 2)
    {
        y = -pow(a, 2);
    }
    else
    {
        y = -4;
    }
    std::cout << y << std::endl;
}
