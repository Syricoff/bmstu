#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов последовательности y: ";
    cin >> n;

    double y[n];

    // Ввод элементов последовательности y
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    // Задаем элементы последовательности x
    double x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Переменная-флаг для определения, был ли найден элемент x[i] в последовательности y
    bool found = false;

    // Проверяем каждый элемент последовательности x
    for (int i = 0; i < 9; i++) {
        found = false;
        for (int j = 0; j < n; j++) {
            if (x[i] == y[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << x[i] << " ";
        }
    }

    cout << endl;

    return 0;
}