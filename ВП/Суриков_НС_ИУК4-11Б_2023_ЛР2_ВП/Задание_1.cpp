#include <cmath>
#include <iostream>

/*
Задание 1
Входные данные для проверки:
-1
1
0.5
3
*/

int main()
{
    double a{}, y{};
    std::cin >> a;
    if (a < 0)
    {
        y = -a;
    }
    else if (0 <= a and a <= 2)
    {
        y = -pow(a, 2);
    }
    else
    {
        y = -4;
    }
    std::cout << y << std::endl;
}
