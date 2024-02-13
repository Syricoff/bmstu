#include <iostream>

struct RationalNumber
{
    int numerator;   // числитель
    int denominator; // знаменатель
};

struct RationalNumber MAX(struct RationalNumber X[], int N)
{
    struct RationalNumber maxNum = X[0];
    for (int i = 1; i < N; i++)
    {
        if (X[i].numerator * maxNum.denominator > maxNum.numerator * X[i].denominator)
        {
            maxNum = X[i];
        }
    }
    return maxNum;
}

int main()
{
    struct RationalNumber numbers[] = {
        {3, 4}, // 0.75
        {2, 5}, // 0.4
        {5, 2}, // 2.5
        {1, 3}  // 0.3333...
    };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    struct RationalNumber maxNumber = MAX(numbers, size);

    std::cout << maxNumber.numerator << '/' << maxNumber.denominator << std::endl;
}