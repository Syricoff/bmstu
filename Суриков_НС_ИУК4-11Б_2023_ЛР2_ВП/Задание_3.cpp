#include <iostream>
#include <cmath>

/*
Задание 3
Входные данные для проверки:

*/

int main()
{
    int m{};
    double f{};
    std::cin >> m;
    switch (m)
    {
    case 1:
        f = log(fabs(m + pow(m, 2))) + sqrt(14);
        break;
    case 2:
        f = log(fabs(m + pow(m, 2))) + sqrt(14);
        break;
    case 3:
        f = (m + 3) / (log(m));
        break;
    case 4:
        f = pow(m, 3) + 2 * (pow(m, 2) + 1);
        break;
    case 5:
        f = 744 - pow(m, 2) * pow(sin(m), 2);
        break;
    case 6:
        f = log(fabs(1 + sqrt(m)));
        break;
    case 7:
        f = pow(m, 3) + 2 * (pow(m, 2) + 1);
        break;
    default:
        f = 0;
        break;
    }
    std::cout << f << std::endl;
}
