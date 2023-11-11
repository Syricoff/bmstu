#include <iostream>
using namespace std;

int main()
{
    int n{};
    cout << "Введите количество вершин многоугольника: ";
    cin >> n;

    int x[n], y[n];
    cout << "Введите координаты вершин многоугольника:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    int xa, ya;
    cout << "Введите координаты точки a: ";
    cin >> xa >> ya;

    // Проверяем, что точка a не совпадает с вершинами многоугольника
    bool isOnVertex = false;
    for (int i = 0; i < n; i++)
    {
        if (xa == x[i] && ya == y[i])
        {
            isOnVertex = true;
            break;
        }
    }

    if (isOnVertex)
    {
        cout << "Точка a лежит на границе многоугольника." << endl;
    }
    else
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int x1 = x[i];
            int y1 = y[i];
            int x2 = x[(i + 1) % n];
            int y2 = y[(i + 1) % n];

            if (((y1 <= ya && ya < y2) || (y2 <= ya && ya < y1)) &&
                (xa < (x2 - x1) * (ya - y1) / (y2 - y1) + x1))
            {
                count++;
            }
        }

        if (count % 2 == 1)
        {
            cout << "Точка a находится внутри многоугольника" << endl;
        }
        else
        {
            cout << "Точка a находится снаружи многоугольника" << endl;
        }
    }
    return 0;
}