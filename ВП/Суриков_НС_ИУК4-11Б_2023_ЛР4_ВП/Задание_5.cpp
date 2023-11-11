#include <iostream>
using namespace std;

int main()
{
    int n{}, m{};
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    int A[n][m];
    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    int count{}; // Счетчик особых элементов

    // Проверяем каждый элемент матрицы
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool is_special = true;

            // Проверка условия (а)
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    sum += A[k][j];
                }
            }
            if (A[i][j] <= sum)
            {
                is_special = false;
            }

            // Проверка условия (б)
            for (int k = 0; k < m; k++)
            {
                if (k != j && A[i][k] > A[i][j])
                {
                    is_special = false;
                    break;
                }
            }
            for (int k = 0; k < j; k++)
            {
                if (A[i][k] < A[i][j])
                {
                    is_special = false;
                    break;
                }
            }

            if (is_special)
            {
                count++;
            }
        }
    }

    cout << "Количество особых элементов: " << count << endl;

    return 0;
}