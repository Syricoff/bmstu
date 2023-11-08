#include <iostream>
#include <cmath>

/*
Задание 3

*/

int main()
{
    double p{1};
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            p *= (1 / (i + pow(j, 2)));
        }
    }
    std::cout << p << std::endl;
}
