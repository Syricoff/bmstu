#include <iostream>
#include <climits>
using namespace std;


int main() {
    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    int X[n][m];

    // Ввод элементов двумерного массива
    cout << "Введите элементы двумерного массива:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> X[i][j];
        }
    }

    int min_elements[n]; // Массив для хранения минимальных элементов каждой строки
    int max_index = 0; // Индекс максимального элемента среди минимальных элементов
    int max_element = INT_MIN; // Максимальный элемент среди минимальных элементов

    // Находим минимальные элементы каждой строки и запоминаем индекс максимального элемента
    for (int i = 0; i < n; i++) {
        int min_element = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (X[i][j] < min_element) {
                min_element = X[i][j];
            }
        }
        min_elements[i] = min_element;
        if (min_element > max_element) {
            max_element = min_element;
            max_index = i;
        }
    }

    // Находим индекс столбца максимального элемента
    int max_column_index = 0;
    for (int j = 0; j < m; j++) {
        if (X[max_index][j] == max_element) {
            max_column_index = j;
            break;
        }
    }

    cout << "Индексы максимального элемента: (" << max_index << ", " << max_column_index << ")" << endl;

    return 0;
}