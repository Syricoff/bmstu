#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double f(double x, double y)
{
    return sqrt(pow(x, 2) + pow(y, 3)) / x + y;
}

double p(int i, double z)
{
    if (i == 1)
        return 3;
    else
        return z * p(i - 1, z) + sqrt(fabs(p(i - 1, z) + 1));
}

double h(int i, double z)
{
    if (i == 1)
        return 8;
    else
        return h(i - 1, z) / (2 * z) + 3 * h(i - 1, z);
}

void multEven(double *sequence, int size, double multiplier)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            sequence[i] *= multiplier;
    }
}

void printArray(double *sequence, int size)
{
    cout << "[";
    for (int i = 0; i < size - 1; i++)
    {
        cout << sequence[i] << ", ";
    }
    cout << sequence[size - 1] << "]" << std::endl;
}

void fillArray(double *sequence, int size)
{
    srand(time(nullptr));

    for (int i = 0; i < size; i++)
    {
        sequence[i] = 10.0 * rand() / (double)RAND_MAX;
    }
}

int main()
{
    double s{}, t{};
    cout << "Enter s, t: ";
    cin >> s >> t;
    double a = f(s, t) + f(pow(s, 2), pow(t, 2));
    double b = f(s, pow(t, 2));
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    double z{};
    cout << "Enter z: ";
    cin >> z;
    double c = pow(p(5, z) + h(3, z), 2);
    cout << "c: " << c << endl;

    const int i = 8;
    const int j = 9;
    const int k = 10;

    double n[i]{};
    double m[j]{};
    double l[k]{};

    fillArray(n, i);
    fillArray(m, j);
    fillArray(l, k);

    std::cout << "n: ";
    printArray(n, i);

    std::cout << "m: ";
    printArray(m, j);

    std::cout << "l: ";
    printArray(l, k);

    multEven(n, i, a);
    multEven(m, j, b);
    multEven(l, k, c);

    std::cout << "n: ";
    printArray(n, i);

    std::cout << "m: ";
    printArray(m, j);

    std::cout << "l: ";
    printArray(l, k);
}
