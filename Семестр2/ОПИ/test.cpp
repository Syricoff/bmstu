#include <cmath>
#include <iostream>

using namespace std;

float factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long double CountSinus(int x, int num)
{
    long double result = 0;
    for (int i = 1; i < num; i++)
    {
        result += ((pow(-1, (i - 1))) / (factorial((2 * i) - 1))) * pow(x, ((2 * i) - 1));
    }
    return result;
}

int main()
{
    cout << CountSinus(1, 1000);
}