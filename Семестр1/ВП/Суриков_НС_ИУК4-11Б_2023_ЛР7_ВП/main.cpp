#include <iostream>
#include <fstream>
#include <cstring>

#include "task_1.h"
#include "task_2.h"

// cd "/home/syricoff/bmstu/ВП/Суриков_НС_ИУК4-11Б_2023_ЛР7_ВП/" && g++ main.cpp task_1.cpp task_2.cpp -o main && "/home/syricoff/bmstu/ВП/Суриков_НС_ИУК4-11Б_2023_ЛР7_ВП/"main

/*
Задача 1
Создать  файл,  содержащий  сведения  о  том,  какие  из  5
предложенных дисциплин желает слушать студент.
Структура записи:
- фамилия студента;
- номер группы;
- средний балл;
- 5 дисциплин, где ‘*’ показывает выбранную дисциплину.
Создать файл, содержащий данные о тех, кто желает прослушать
дисциплину ХХ. Если желающих больше 10, то отобрать тех студентов,
у которых более высокий средний балл
Задача 2
Написать  программу  сравнения  двух  файлов:  должна  печататься
первая строка, в которой они различаются. Если файлы идентичны, то
выдать сообщение.
*/

using namespace std;

void printMenu();

int main()
{
    int choice;

    do
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
            break;
        }

        cout << endl;

    } while (choice != 0);
}

void printMenu()
{
    cout << "Меню:" << endl;
    cout << "1. Задание 1" << endl;
    cout << "2. Задание 2" << endl;
    cout << "0. Выход" << std::endl;
    cout << "Выберите номер задания: ";
}
