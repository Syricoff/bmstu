#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Максимальное количество цифр в числе Фибоначчи

int main()
{
    int n;
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;

    int fib1[MAX_SIZE]{0};   // Первое число Фибоначчи
    int fib2[MAX_SIZE]{0};   // Второе число Фибоначчи
    int result[MAX_SIZE]{0}; // Результат

    fib2[0] = 1; // Инициализация второго числа Фибоначчи как 1

    if (n == 1)
    {
        cout << "Число Фибоначчи: 0" << endl;
        return 0;
    }
    else if (n == 2)
    {
        cout << "Число Фибоначчи: 1" << endl;
        return 0;
    }

    
    for (int i = 3; i <= n; i++)
    {
        // Сложение двух чисел Фибоначчи
        int carry = 0; // Перенос разряда

        for (int j = 0; j < MAX_SIZE; j++)
        {
            int digitSum = fib1[j] + fib2[j] + carry; // Сумма цифр на текущем разряде
            result[j] = digitSum % 10;                // Записываем последнюю цифру суммы
            carry = digitSum / 10;                    // Вычисляем перенос разряда
        }

        // Обновляем значения чисел Фибоначчи для следующей итерации
        for (int j = 0; j < MAX_SIZE; j++)
        {
            fib1[j] = fib2[j];
            fib2[j] = result[j];
        }
    }

    cout << "Число Фибоначчи: ";
    for (int i = MAX_SIZE - 1; i >= 0; i--)
    {
        if (result[i] != 0)
        {
            cout << result[i];
        }
    }

    cout << endl;

    return 0;
}