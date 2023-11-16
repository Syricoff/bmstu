#include <iostream>
using namespace std;

/*
4
0 0
0 4
4 4
4 0
2 2

3
0 0
0 4
4 0
2 5

5
0 0
0 4
4 4
4 2
2 0
1 1
4
0 0
0 4
4 4
4 0
2 2
6
0 0
0 4
2 5
4 4
4 0
2 -1
5 3
*/

int main()
{
    int n{};
    cout << "Введите количество вершин: ";
    cin >> n;

    int x[n], y[n];
    cout << "Введите координаты вершин: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    int xa, ya;
    cout << "Введите координаты точки: ";
    cin >> xa >> ya;

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
        cout << "Внутри многоугольника" << endl;
    }
    else
    {
        cout << "Снаружи многоугольника" << endl;
    }

    return 0;
}