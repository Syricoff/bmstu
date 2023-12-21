#include <iostream>
#include <fstream>
#include <cstring>

#include "task_1.h"
#include "task_2.h"

// clang++-17 main.cpp task_1.cpp task_2.cpp -o main && ./main
/*
Вариант 8 
Задача 1 
Запись  имеет  вид:  
номер  читательского  билета,  
автор  книги, 
название, 
дата заказа.  

Создать файл из 10 записей, просмотреть файл, 
добавить  в  файл  (в  начало  и  конец)  новую  информацию.  Поменять 
местами первую и последнюю записи в файле.  

Задача 2 
Для  произвольного  текстового  файла  программа  составляет  файл 
записей  фиксированной  длины,  содержащий  файловые  указатели  на 
строки  текстового  файла.  Программа  производит  логическую 
перестановку строк, не меняя самого текстового файла.
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
