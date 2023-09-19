#include <iostream>
#include <cmath>
#include <iomanip> // Для вывода с достаточным количеством знаков после запятой

/*
Задание 1
Входные данные для проверки:
d m a b
5 4 13.1 0.7 -> 29.092251, 69.997534 
6 7 8.9 10.1 -> 1064.788563, 182.179016
5 9 0.4 0.1  -> 25.993288, 68.640203
*/

int main()
{
    int d{}, m{};
    double a{}, b{};
    std::cin >> d >> m >> a >> b;
    double z = pow(d, 2) + pow(sin(pow((m + 4), 2)), 2) + sqrt(fabs((a - pow(b, m)) / sqrt(pow(b, 2) + 1)));
    double r = (tan(pow((m + 1), 2)) + 4.12 * exp(d - 1)) / (log(fabs(d + m + pow(1.75, 5)))) + 3 * cos(2 * b);
    std::cout << std::fixed << z << "\n" << r << std::endl;
}
