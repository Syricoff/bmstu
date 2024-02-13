#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265

using namespace std;

int main()
{
    const int m = 6;
    const int n = 6;

    // Строим матрицу А
    int A[m][n]{};
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            A[i - 1][j - 1] = i + sqrt(j) / sin(i * PI / 180);
        }
    }

    // Получаем индексы максимального и минимального элементов A
    int minRow{}, maxRow{};
    int minElem = A[0][0], maxElem = A[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] < minElem)
            {
                minElem = A[i][j];
                minRow = i;
            }
            if (A[i][j] > maxElem)
            {
                maxElem = A[i][j];
                maxRow = i;
            }
        }
    }

    // Копируем матрицу A в B
    int B[m][n]{};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = A[i][j];
        }
    }

    // Меняем местами строки с минимальным и максимальным элементами
    for (int j = 0; j < n; j++)
    {
        int temp = B[minRow][j];
        B[minRow][j] = B[maxRow][j];
        B[maxRow][j] = temp;
    }

    // Строим матрицу С
    int C[6][6]{};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
                C[i][j] = 6;
            else
                C[i][j] = i + 1;
        }
    }

    // Вычисляем D=B*C
    int D[m][6]{};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < n; k++)
            {
                D[i][j] += B[i][k] * C[k][j];
            }
        }
    }

    // Копируем матрицу D в E
    int E[6][6]{};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            E[i][j] = D[i][j];
        }
    }

    // Меняем 2 и 3 блоки
    for (int i = 0; i < 2; i++)
    {
        for (int j = 2; j < 4; j++)
        {
            int temp = E[i][j];
            E[i][j] = E[i][j + 2];
            E[i][j + 2] = temp;
        }
    }

    // Меняем 4 и 7 блоки
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int temp = E[i][j];
            E[i][j] = E[i + 2][j];
            E[i + 2][j] = temp;
        }
    }

    // Делаем вычисления для матрицы Е
    int sumNeg{};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (E[i][j] < 0)
                sumNeg += E[i][j];
        }
    }

    // Вывести матрицы А, В, С, D, Е и результат вычисления пункта 6 задания
    cout << "Матрица A:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Матрица B:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Матрица C:" << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << setw(5) << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Матрица D:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << setw(5) << D[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Матрица E:" << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << setw(5) << E[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Сумма отрицательных элементов матрицы E: " << sumNeg << endl;

    return 0;
}