#include <iostream>
#include <cmath>

// 5 4 13.1 0.7  + sqrt(fabs(a - pow(b, m) / sqrt(pow(b, 2) + 1)));
int main()
{
    int d, m;
    float a, b;
    std::cin >> d >> m >> a >> b;
    double z = pow(d, 2) + pow(sin(pow((m + 4), 2)), 2);
    std::cout << z << std::endl;
}
