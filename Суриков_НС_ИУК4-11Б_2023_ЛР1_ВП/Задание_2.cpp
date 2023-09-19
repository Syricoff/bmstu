#include <iostream>
#include <cmath>

/*
Задание 2
Входные данные для проверки:
x y
-2 2 true
3 2.645 true
-4 -2 true
1 -1 false
*/

int main()
{
    double x, y;
    std::cin >> x >> y;
    bool isInArea = (x >= 0 and y >= 0 and (pow(x, 2) + pow(y, 2) <= 16)) or (x <= 0 and y >= 0 and (y - x <= 4)) or (x <= 0 and y <= 0 and x >= -4 and y >= -2);
    std::cout << std::boolalpha << isInArea << std::endl;
}
