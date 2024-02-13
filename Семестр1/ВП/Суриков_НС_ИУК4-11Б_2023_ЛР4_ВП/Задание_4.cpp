#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int X[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i][j];
        }
    }

    int min_elems[n];       // Массив для хранения минимальных элементов каждой строки
    int max_index = 0;         // Индекс максимального элемента среди минимальных элементов
    int max_elem = -10e4; // Максимальный элемент среди минимальных элементов

    // Находим минимальные элементы каждой строки и запоминаем индекс максимального элемента
    for (int i = 0; i < n; i++)
    {
        int min_elem = 10e4;
        for (int j = 0; j < m; j++)
        {
            if (X[i][j] < min_elem)
            {
                min_elem = X[i][j];
            }
        }
        min_elems[i] = min_elem;
        if (min_elem > max_elem)
        {
            max_elem = min_elem;
            max_index = i;
        }
    }

    // Находим индекс столбца максимального элемента
    int max_col_index = 0;
    for (int j = 0; j < m; j++)
    {
        if (X[max_index][j] == max_elem)
        {
            max_col_index = j;
            break;
        }
    }

    cout << "(" << max_index << ", " << max_col_index << ")" << endl;

    return 0;
}