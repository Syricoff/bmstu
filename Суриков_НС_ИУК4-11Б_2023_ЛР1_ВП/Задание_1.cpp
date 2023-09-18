#include <iostream>
#include <cmath>
#include <iomanip> // Для вывода с достаточным количеством знаков после запятой

/*
Задание 1
Входные данные для проверки:
5 4 13.1 0.7 -> 29.0923
6 7 8.9 10.1 -> 1064.79
5 9 0.4 0.1  -> 25.9933
*/

int main()
{
    int d, m;
    double a, b;
    std::cin >> d >> m >> a >> b;
    double z = pow(d, 2) + pow(sin(pow((m + 4), 2)), 2) + sqrt(fabs((a - pow(b, m)) / sqrt(pow(b, 2) + 1)));
    std::cout << std::fixed << z << std::endl;
}
