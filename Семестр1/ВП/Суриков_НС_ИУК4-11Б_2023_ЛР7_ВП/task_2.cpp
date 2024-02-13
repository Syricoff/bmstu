#include <iostream>
#include <fstream>
#include <cstring>

#include "task_2.h"

using namespace std;

void compareFiles(const char *file1, const char *file2)
{
    ifstream fсout1(file1);
    ifstream fсout2(file2);

    if (fсout1.is_open() && fсout2.is_open())
    {
        char line1[256], line2[256];
        int lineNum = 1;

        while (fсout1.getline(line1, 256) && fсout2.getline(line2, 256))
        {
            if (strcmp(line1, line2) != 0)
            {
                cout << "Файлы различаются в строке " << lineNum << ":" << endl;
                cout << file1 << ": " << line1 << endl;
                cout << file2 << ": " << line2 << endl;
                return;
            }
            lineNum++;
        }

        if (!fсout1.eof() || !fсout2.eof())
        {
            cout << "Файлы имеют разное число строк" << endl;
        }
        else
        {
            cout << "Файлы идентичны" << endl;
        }
    }
    else
    {
        cout << "Невозможно открыть файл" << endl;
    }

    fсout1.close();
    fсout2.close();
}

void task_2()
{
    char file1[256];
    char file2[256];

    cout << "Введите имя первого файла: ";
    cin >> file1;

    cout << "Введите имя второго файла: ";
    cin >> file2;

    compareFiles(file1, file2);
}