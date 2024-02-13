#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>
#include <limits> // для numeric_limits

/* Используя одномерные массивы, составить список учебной группы в соответ-
ствии с вариантом задания.
Используя меню, обеспечить:
⎯ ввод информации с клавиатуры,
⎯ ввод информации из уже созданного текстового файла (загрузку базы
данных),
⎯ ввод информации из уже созданного бинарного файла (загрузку базы
данных),
⎯ вывод данных (распечатку ее в виде таблицы) на экран,
⎯ вывод данных в файл,
⎯ распечатку информации данных по запросу,
⎯ перевод базы данных в текстовый файл,
⎯ перевод содержимого текстового файла в бинарный файл,
⎯ добавление записи,
⎯ изменение записи,
⎯ удаление записи,
⎯ сортировка по любому из полей и в любом направлении,
⎯ выход.

Задание на октябрь (30% от всего объёма работы):
1. Организовать меню с обозначенным набором задач.
2. Осуществить ввод информации с клавиатуры.
3. Осуществить вывод данных на экран (распечатка в виде таблицы).
4. Обеспечить распечатку данных по запросу.

Вариант 11
Составить список учебной группы. Авторизация!!!!  Для каждого студента указать фамилию,
имя, отчество, год рождения, год поступления, курс, группа, оценки по трем предметам.
Запрос: упорядочить данные по году рождения.

*/

using namespace std;

struct Student
{
    char surname[30]{};
    char name[30]{};
    char patronymic[30]{};
    short birthYear{};
    short course{};
    short informatics{};
    short physics{};
    short math{};
};

Student students[50] = {
    {"Иванов", "Иван", "Иванович", 2000, 3, 4, 5, 3},
    {"Петров", "Петр", "Петрович", 1999, 2, 3, 4, 5},
    {"Сидоров", "Алексей", "Алексеевич", 2001, 1, 5, 4, 4},
    {"Смирнова", "Елена", "Александровна", 2000, 2, 4, 5, 3},
    {"Козлов", "Дмитрий", "Иванович", 2001, 1, 3, 4, 5},
    {"Васильева", "Анна", "Петровна", 1999, 3, 5, 4, 4},
    {"Николаев", "Александр", "Владимирович", 2000, 2, 4, 5, 3},
    {"Морозова", "Ольга", "Андреевна", 2001, 1, 3, 4, 5},
    {"Соколов", "Максим", "Дмитриевич", 1999, 3, 5, 4, 4},
    {"Павлова", "Екатерина", "Алексеевна", 2000, 2, 4, 5, 3}
};

int iter{};

// Очищает буфер ввода для корректной работы cin
void ignoreLine()
{
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

// bool isNumber(char Symbol) {return (Symbol >= '0' && Symbol <= '9');}

void addStudent()
{
    Student student{};

    cout << "Введите имя:" << endl;
    // Валидация ввода имени
    while (true)
    {
        cin >> setw(30) >> student.name;
        if (cin.fail())
        {
            cout << "Ошибка: неверный формат имени. Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }

    cout << "Введите фамилию:" << endl;
    // Валидация ввода фамилии
    while (true)
    {
        cin >> setw(30) >> student.surname;
        if (cin.fail())
        {
            cout << "Ошибка: неверный формат фамилии. Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }

    cout << "Введите отчество:" << endl;
    // Валидация ввода отчества
    while (true)
    {
        cin >> setw(30) >> student.patronymic;
        if (cin.fail())
        {
            cout << "Ошибка: неверный формат отчества. Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }

    cout << "Введите год рождения:" << endl;
    // Валидация ввода года рождения
    while (true)
    {
        cin >> student.birthYear;
        if (cin.fail() or student.birthYear < 1900 or student.birthYear > 2023)
        {
            cout << "Ошибка: неверный формат года рождения. ";
            cout << "Год должен быть в диапазоне от 1900 до 2023. ";
            cout << "Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }

    cout << "Введите номер курса:" << endl;
    // Валидация ввода номера курса
    while (true)
    {
        cin >> student.course;
        if (cin.fail())
        {
            cout << "Ошибка: неверный формат номера курса. Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }


    cout << "Введите оценку по информатике:" << endl;
    // Валидация ввода оценки
    while (true)
    {
        cin >> student.informatics;
        if (cin.fail())
        {
            cout << "Ошибка: неверный формат оценки. Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }

    cout << "Введите оценку по физике:" << endl;
    // Валидация ввода оценки
    while (true)
    {
        cin >> student.physics;
        if (cin.fail())
        {
            cout << "Ошибка: неверный формат оценки. Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }

    cout << "Введите оценку по математике:" << endl;
    // Валидация ввода оценки
    while (true)
    {
        cin >> student.math;
        if (cin.fail())
        {
            cout << "Ошибка: неверный формат оценки. Попробуйте еще раз." << endl;
            cin.clear();
            ignoreLine();
        }
        else
        {
            break;
        }
    }

    students[iter] = student;
    iter++;
}

void printStudents() {
    int count = size(students);
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "| Фамилия | Имя | Отчество | Год рождения | Курс | Оценки |" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << "| " << students[i].surname << " | " << students[i].name << " | " << students[i].patronymic
                  << " | " << students[i].birthYear << " | " << students[i].course << " | " 
                  << students[i].informatics << ' ' << students[i].physics << ' ' << students[i].math << " | " << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}


/* void getAllStudents()
{
    int maxLengths[6] = {};
    for (int i = 0; i < sizeof(students); i++) {
        if (sizeof(students[i].name) > maxLengths[0]) maxLengths[0] = sizeof(students[i].name);
        if (sizeof(students[i].surname) > maxLengths[1]) maxLengths[1] = sizeof(students[i].surname);
        if (sizeof(students[i].entryYear) > maxLengths[2]) maxLengths[2] = sizeof(students[i].entryYear);
        if (sizeof(students[i].birthYear) > maxLengths[3]) maxLengths[3] = sizeof(students[i].birthYear);
        if (sizeof(students[i].year) > maxLengths[4]) maxLengths[4] = sizeof(students[i].year);
        if (sizeof(students[i].group) > maxLengths[5]) maxLengths[5] = sizeof(students[i].group);
    }

    cout << "| " << left << setw(maxLengths[0]) << "Name"
         << " | ";
    cout << left << setw(maxLengths[1]) << "Surname"
         << " | ";
    cout << left << setw(maxLengths[2]) << "Patronymic"
         << " | ";
    cout << left << setw(maxLengths[3]) << "Birth Year"
         << " | ";
    cout << left << setw(maxLengths[4]) << "Course"
         << " |" << endl;

    for (int maxLength : maxLengths)
    {
        cout << "+";
        for (int j = 0; j < maxLength; j++)
        {
            cout << "-";
        }
    }
    cout << endl;

    for (int i = 0; i < size(students); i++)
    {
        cout << "| " << left << setw(maxLengths[0]) << students[i].name << " | ";
        cout << left << setw(maxLengths[1]) << students[i].surname << " | ";
        cout << left << setw(maxLengths[2]) << students[i].patronymic << " | ";
        cout << left << setw(maxLengths[3]) << students[i].birthYear << " | ";
        cout << left << setw(maxLengths[4]) << students[i].course << " | " << endl;
    }
 
    for (int maxLength : maxLengths)
    {
        cout << "+";
        for (int j = 0; j < maxLength + 2; j++)
        {
            cout << "-";
        }
        cout << "+";
    }
    cout << endl;
} */

void sortByBirthYear() {
    int count = size(students);
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].birthYear > students[j+1].birthYear) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    printStudents();
}

void showMenu()
{
    cout << "Введите номер пункта меню:\n" << endl;
    cout << "0. Ввести информацию" << endl;
    cout << "1. Ввести информацию из существующего текстового файла" << endl;
    cout << "2. Ввести информацию из существующего двоичного файла" << endl;
    cout << "3. Отобразить данные" << endl;
    cout << "4. Вывести данные в файл" << endl;
    cout << "5. Распечатать информацию" << endl;
    cout << "6. Преобразовать базу данных в файл" << endl;
    cout << "7. Преобразовать содержимое текстового файла в двоичный файл" << endl;
    cout << "8. Добавить запись" << endl;
    cout << "9. Изменить запись" << endl;
    cout << "10. Удалить запись" << endl;
    cout << "11. Сортировать по любому полю" << endl;
    cout << "12. Выход" << endl;
    cout << "13. Запрос" << endl;
    cout << "" << endl;
}

void menuHandler(short choice)
{
    switch (choice)
    {
    case 0:
        cout << "Ввести информацию" << endl;
        break;
    case 1:
        cout << "Ввести информацию из существующего текстового файла" << endl;
        break;
    case 2:
        cout << "Ввести информацию из существующего двоичного файла" << endl;
        break;
    case 3:
        cout << "Отобразить данные" << endl;
        printStudents();
        break;
    case 4:
        cout << "Вывести данные в файл" << endl;
        break;
    case 5:
        cout << "Распечатать информацию" << endl;
        break;
    case 6:
        cout << "Преобразовать базу данных в файл" << endl;
        break;
    case 7:
        cout << "Преобразовать содержимое текстового файла в двоичный файл" << endl;
        break;
    case 8:
        cout << "Добавить запись" << endl;
        addStudent();
        break;
    case 9:
        cout << "Изменить запись" << endl;
        break;
    case 10:
        cout << "Удалить запись" << endl;
        break;
    case 11:
        cout << "Сортировать по любому полю" << endl;
        break;
    case 12:
        cout << "Выход" << endl;
        exit(0);
    case 13:
        cout << "Запрос" << endl;
        sortByBirthYear();
        break;
    default:
        cout << "Неверный номер пункта меню." << endl;
        break;
    }
}

int main()
{
    while (true)
    {
        showMenu();
        cout << "Введите номер пункта меню: ";
        short choice{};
        while (!(cin >> choice))
        {
            cin.clear();
            ignoreLine();
            cout << "Неверный ввод. Пожалуйста, введите правильный номер пункта меню: ";
        }
        menuHandler(choice);
    }
}
