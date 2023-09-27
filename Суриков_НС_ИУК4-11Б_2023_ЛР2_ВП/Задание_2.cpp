#include <iostream>
#include <cmath>

/*
Задание 2
Входные данные для проверки:
-2 -4
-10 5
-6 -10
6 7
*/

int main()
{
    double a{}, b{};
    std::cin >> a >> b;
    if (a == -10 or b == -10)
    {
        a = 1;
        b = 1;
    }
    else if (a < 0 and b < 0)
    {
        a = 0;
        b = 0;
    }
    else
    {
        (a > b) ? (b *= 1000) : (a *= 1000);
    }

    std::cout << a << " " << b << std::endl;
}
