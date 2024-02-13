#include <iostream>
#include <cmath>

/*
Задание 3
Входные данные для проверки:
1	2	3	4	5	6	7	0
4.4348	5.53342	5.46144	98	721.012	1.23823	443	Wrong input
*/

int main()
{
    int m{};
    double f{};
    bool isCorrInp{ true };
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
        isCorrInp = false;
        break;
    }
    if (isCorrInp)
    {
        std::cout << f << std::endl;
    }
    else {
        std::cout << "Wrong input" << std::endl;
    }
}
