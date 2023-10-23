#include "Student.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>


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
Составить список учебной группы. Для каждого студента указать фамилию,
имя, отчество, год рождения, курс, оценки по трем предметам.
Запрос: упорядочить данные по году рождения.

*/

using namespace std;

struct Student {

    char name[30]{};
    char surname[30]{};
    short entryYear{};
    short birthYear{};
    unsigned short year{};
    char group[12]{};
};

Student students = Student[50];
int border = 0;

void checkSize();

void changeSize();

int partition(Student *students, int low, int high, bool reversed);

void sortStudentsByAge(Student *students, int low, int high, bool reversed);

void addStudent();

void getAllStudents();

void request();

void showMenu();

void menuHandler(short choice);

int partition(int low, int high, bool reversed) {
    int pivot = students[high].birthYear;
    int i = low;

    for (int j = low; j < high; ++j) {
        if ((reversed && students[j].birthYear > pivot) || (!reversed && students[j].birthYear < pivot)) {
            swap(students[i], students[j]);
            ++i;
        }
    }
    swap(students[i], students[high]);
    return i;
}

void sortStudentsByAge(int low, int high, bool reversed) {
    if (low < high) {
        int pivotIndex = partition(low, high, reversed);
        sortStudentsByAge(students, low, pivotIndex - 1, reversed);
        sortStudentsByAge(students, pivotIndex + 1, high, reversed);
    }
}

void addStudent() {
    Student student{};
    cout << "Введите имя, фамилию, год рождения, год поступления, курс и группу студента (разделенные пробелами):\n";

    // Validate name input
    while (true) {
        cin >> setw(30) >> student.name;
        if (cin.fail()) {
            cerr << "Ошибка: неверный формат имени. Попробуйте еще раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Validate surname input
    while (true) {
        cin >> setw(30) >> student.surname;
        if (cin.fail()) {
            cerr << "Ошибка: неверный формат фамилии. Попробуйте еще раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Validate birth year input
    while (true) {
        cin >> student.birthYear;
        if (cin.fail() || student.birthYear < 1900 || student.birthYear > 2023) {
            cerr
                    << "Ошибка: неверный формат года рождения. Год должен быть в диапазоне от 1900 до 2023. Попробуйте еще раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Validate entry year input
    while (true) {
        cin >> student.entryYear;
        if (cin.fail() || student.entryYear < 2000 || student.entryYear > 2023) {
            cerr
                    << "Ошибка: неверный формат года поступления. Год должен быть в диапазоне от 1900 до 2023. Попробуйте еще раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Validate year input
    while (true) {
        cin >> student.year;
        if (cin.fail() || student.year < 1 || student.year > 6) {
            cerr << "Ошибка: неверный формат курса. Курс должен быть в диапазоне от 1 до 6. Попробуйте еще раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Validate group input
    while (true) {
        cin >> setw(12) >> student.group;
        if (cin.fail()) {
            cerr << "Ошибка: неверный формат группы. Попробуйте еще раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    checkSize();
    students[border] = student;
    border += 1;
}

void checkSize() {
    if (border == sizeof(students)) {
        changeSize();
    }
}

void changeSize() {
    int length = (border + 1) * 2;
    Student *newStudents = new Student[length];
    for (int i = 0; i <= border; ++i) {
        newStudents[i] = students[i];
    }
    *students = *new Student[length];
    for (int i = 0; i < border; ++i) {
        students[i] = newStudents[i];
    }
    delete[] newStudents;
}


void getAllStudents() {
    // Find max length for each column
    int maxLengths[6] = {sizeof("Name") - 1, sizeof("Surname") - 1, sizeof("Entry Year") - 1,
                         sizeof("Birth Year") - 1,
                         sizeof("Year") - 1, sizeof("Group") - 1};
    for (int i = 0; i < sizeof(students); i++) {
        if (sizeof(students[i].name) > maxLengths[0]) maxLengths[0] = sizeof(students[i].name);
        if (sizeof(students[i].surname) > maxLengths[1]) maxLengths[1] = sizeof(students[i].surname);
        if (sizeof(students[i].entryYear) > maxLengths[2]) maxLengths[2] = sizeof(students[i].entryYear);
        if (sizeof(students[i].birthYear) > maxLengths[3]) maxLengths[3] = sizeof(students[i].birthYear);
        if (sizeof(students[i].year) > maxLengths[4]) maxLengths[4] = sizeof(students[i].year);
        if (sizeof(students[i].group) > maxLengths[5]) maxLengths[5] = sizeof(students[i].group);
    }

    // Print header row
    cout << "| " << left << setw(maxLengths[0]) << "Name" << " | ";
    cout << left << setw(maxLengths[1]) << "Surname" << " | ";
    cout << left << setw(maxLengths[2]) << "Entry Year" << " | ";
    cout << left << setw(maxLengths[3]) << "Birth Year" << " | ";
    cout << left << setw(maxLengths[4]) << "Year" << " | ";
    cout << left << setw(maxLengths[5]) << "Group" << " |\n";

    // Print separator row
    for (int maxLength: maxLengths) {
        cout << "+";
        for (int j = 0; j < maxLength + 2; j++) {
            cout << "-";
        }
        cout << "+";
    }
    cout << "\n";

    // Print data rows
    for (int i = 0; i < sizeof(students); i++) {
        cout << "| " << left << setw(maxLengths[0]) << students[i].name << " | ";
        cout << left << setw(maxLengths[1]) << students[i].surname << " | ";
        cout << left << setw(maxLengths[2]) << students[i].entryYear << " | ";
        cout << left << setw(maxLengths[3]) << students[i].birthYear << " | ";
        cout << left << setw(maxLengths[4]) << students[i].year << " | ";
        cout << left << setw(maxLengths[5]) << students[i].group << " |\n";
    }

    // Print footer row
    for (int maxLength: maxLengths) {
        cout << "+";
        for (int j = 0; j < maxLength + 2; j++) {
            cout << "-";
        }
        cout << "+";
    }
    cout << "\n";
}

// Запрос: Получить фамилии и группы двух самых молодых студентов по возрасту
void request() {
    sortStudentsByAge(students, 0, (sizeof(students) / sizeof(students[0])) - 1, false);
    cout << "Фамилия: " << students[0].surname << ", Год рождения: " << students[0].birthYear << endl;
    cout << "Фамилия: " << students[1].surname << ", Год рождения: " << students[1].birthYear << endl;
}

void showMenu() {
    cout << "Введите номер пункта меню:\n\n";
    cout << "0. Ввести информацию\n";
    cout << "1. Ввести информацию из существующего текстового файла\n";
    cout << "2. Ввести информацию из существующего двоичного файла\n";
    cout << "3. Отобразить данные\n";
    cout << "4. Вывести данные в файл\n";
    cout << "5. Распечатать информацию\n";
    cout << "6. Преобразовать базу данных в файл\n";
    cout << "7. Преобразовать содержимое текстового файла в двоичный файл\n";
    cout << "8. Добавить запись\n";
    cout << "9. Изменить запись\n";
    cout << "10. Удалить запись\n";
    cout << "11. Сортировать по любому полю\n";
    cout << "12. Выход\n";
    cout << "13. Запрос\n";
    cout << "\n";
}

void menuHandler(short choice) {
    switch (choice) {
        case 0:
            cout << "Ввести информацию\n";
            break;
        case 1:
            cout << "Ввести информацию из существующего текстового файла\n";
            break;
        case 2:
            cout << "Ввести информацию из существующего двоичного файла\n";
            break;
        case 3:
            cout << "Отобразить данные\n";
            getAllStudents();
            break;
        case 4:
            cout << "Вывести данные в файл\n";
            break;
        case 5:
            cout << "Распечатать информацию\n";
            break;
        case 6:
            cout << "Преобразовать базу данных в файл\n";
            break;
        case 7:
            cout << "Преобразовать содержимое текстового файла в двоичный файл\n";
            break;
        case 8:
            cout << "Добавить запись\n";
            addStudent();
            break;
        case 9:
            cout << "Изменить запись\n";
            break;
        case 10:
            cout << "Удалить запись\n";
            break;
        case 11:
            cout << "Сортировать по любому полю\n";
            break;
        case 12:
            cout << "Выход\n";
            exit(0);
        case 13:
            cout << "Запрос\n";
            request();
        default:
            cout << "Неверный номер пункта меню.\n";
            break;
    }
}

int main() {
    while (true) {
        showMenu();
        short choice;
        cout << "Введите номер пункта меню: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Пожалуйста, введите правильный номер пункта меню: ";
        }
        menuHandler(choice);
    }
}
