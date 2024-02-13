#include <iostream>
#include <fstream>

#include <iomanip> // для setw()
#include <cstring>
#include <limits> // для numeric_limits

#include <stdio.h> // для getchar()
#include <format>  // для format()

#include "main.h"

using namespace std;

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

Вариант 11
Составить список учебной группы. Для каждого студента указать фамилию,
имя, отчество, год рождения, год поступления, курс, оценки по трем предметам.
Запрос: упорядочить данные по году рождения.

*/

int main()
{
    setlocale(LC_ALL, "Russian");

    int studentsNumber{0};
    Student *students = new Student[studentsNumber];
    while (true)
    {
        int opt;
        clearDisplay();
        printMenu();

        allowedValues_i = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 0};
        opt = getInput(allowedValues_i, 10);
        delete[] allowedValues_i;
        allowedValues_i = nullptr;

        switch (opt)
        {
        case 1:
            clearDisplay();
            addStudent(students, studentsNumber);
            break;
        case 2:
            clearDisplay();
            changeStudent(students, studentsNumber);
            break;
        case 3:
            clearDisplay();
            deleteStudent(students, studentsNumber);
            break;
        case 4:
            clearDisplay();
            displayStudentList(students, studentsNumber);
            break;
        case 5:
            clearDisplay();
            displaySortedStudentList(students, studentsNumber);
            break;
        case 6:
            clearDisplay();
            importStudentList(students, studentsNumber);
            break;
        case 7:
            clearDisplay();
            exportStudentList(students, studentsNumber);
            break;
        case 8:
            clearDisplay();
            transformStudentList();
            break;
        case 0:
            exit(0);
        default:
            cerr << "\nError: case default in main\n ";
            break;
        }
    }
}

void clearDisplay()
{
    cout << "\x1B[2J\x1B[H";
}

void clearInput()
{
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void addStudent(Student *&students, int &studentsNumber)
{
    cout << "Укажите количество студентов, которое требуется добавить (0 - отмена операции): ";
    int studNum;
    while (true)
    {
        studNum = getInput();
        if (studNum < 0)
            cout << "Некорректный ввод. Пожалуйста, введите правильное значение : ";
        else if (studNum == 0)
        {
            cout << "\nДобавление студентов прервано.\n"
                 << endl
                 << "Для возврата в меню нажмите enter... ";
            getchar();
            return;
        }
        else
            break;
    }

    Student *temp = new Student[studentsNumber + studNum];
    for (int i = 0; i < studentsNumber; i++)
        temp[i] = students[i];

    for (int i = 0; i < studNum; i++)
    {
        Student stud;
        cout << "Введите фамилию студента №" << i + 1 << ": ";
        strcpy(stud.surname, getInput(21));

        cout << "Введите имя студента №" << i + 1 << ": ";
        strcpy(stud.name, getInput(21));

        cout << "Введите отчество студента №" << i + 1 << ": ";
        strcpy(stud.patronymic, getInput(21));

        cout << "Введите год рождения студента №" << i + 1 << " (1900 - 2023): ";
        allowedValues_i = new int[2023 - 1900 + 1];
        for (int i = 0; i < 2023 - 1900 + 1; i++)
            allowedValues_i[i] = i + 1900;
        stud.birthYear = getInput(allowedValues_i, 2023 - 1900 + 1);
        delete[] allowedValues_i;

        cout << "Введите курс обучения студента №" << i + 1 << " (1 - 6):";
        allowedValues_i = new int[6]{1, 2, 3, 4, 5, 6};
        stud.course = getInput(allowedValues_i, 6);
        delete[] allowedValues_i;

        cout << "Введите оценки студента №" << i + 1 << " по 3 предметам (0 - 5) :" << endl;

        cout << "Оценка 1: ";
        allowedValues_i = new int[6]{0, 1, 2, 3, 4, 5};
        stud.marks[0] = getInput(allowedValues_i, 6);

        cout << "Оценка 2: ";
        stud.marks[1] = getInput(allowedValues_i, 6);

        cout << "Оценка 3: ";
        stud.marks[2] = getInput(allowedValues_i, 6);

        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        temp[studentsNumber + i] = stud;
    }
    delete[] students;
    students = temp;
    studentsNumber += studNum;

    cout << "\nДобавление студентов выполнено успешно!\n"
         << endl;
    cout << "Для возврата в меню нажмите enter... ";
    getchar();
}

void changeStudent(Student *&students, int studentsNumber)
{
    if (!isStudents(studentsNumber))
        return;

    printStudentList(students, studentsNumber);

    cout << "\nУкажите номер студента, которого требуется изменить (0 - отмема операции): ";

    allowedValues_i = new int[studentsNumber + 1];
    for (int i = 0; i <= studentsNumber; i++)
        allowedValues_i[i] = i;
    int changeStud = getInput(allowedValues_i, studentsNumber + 1);
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    if (changeStud == 0)
    {
        cout << "\nИзменение студента прервано.\n\nДля возврата в меню нажмите enter... ";
        getchar();
        return;
    }

    cout << "\nУкажите поле, которое требуется изменить:\n "
         << "1 - Фамилия\n "
         << "2 - Имя\n "
         << "3 - Отчество\n "
         << "4 - Год рождения\n "
         << "5 - Курс обучения\n "
         << "6 - Оценка 1\n "
         << "7 - Оценка 2\n "
         << "8 - Оценка 3\n ";
    cout << "Данные для изменения: ";

    allowedValues_i = new int[8]{1, 2, 3, 4, 5, 6, 7, 8};
    int changeMode = getInput(allowedValues_i, 8);
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    switch (changeMode)
    {
    case 1:
    {
        cout << "Введите новую фамилию студента: ";
        strcpy(students[changeStud - 1].surname, getInput(21));
        break;
    }
    case 2:
    {
        cout << "Введите новое имя студента: ";
        strcpy(students[changeStud - 1].name, getInput(21));
        break;
    }
    case 3:
    {
        cout << "Введите новое отчество студента: ";
        strcpy(students[changeStud - 1].patronymic, getInput(21));
        break;
    }
    case 4:
    {
        cout << "Введите новый год рождения студента (1900 - 2022):";
        allowedValues_i = new int[2022 - 1900 + 1];
        for (int i = 0; i < 2022 - 1900 + 1; i++)
            allowedValues_i[i] = i + 1900;
        students[changeStud - 1].birthYear = getInput(allowedValues_i, 2022 - 1900 + 1);
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        break;
    }
    case 5:
    {
        cout << "Введите новый курс обучения студента (1 - 6): ";
        allowedValues_i = new int[6]{1, 2, 3, 4, 5, 6};
        students[changeStud - 1].course = getInput(allowedValues_i, 6);
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        break;
    }
    case 6:
    {
        cout << "Введите новую оценку 1 студента (0 - 5): ";
        allowedValues_i = new int[6]{0, 1, 2, 3, 4, 5};
        students[changeStud - 1].marks[0] = getInput(allowedValues_i, 6);
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        break;
    }
    case 7:
    {
        cout << "Введите новую оценку 2 студента (0 - 5): ";
        allowedValues_i = new int[6]{0, 1, 2, 3, 4, 5};
        students[changeStud - 1].marks[1] = getInput(allowedValues_i, 6);
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        break;
    }
    case 8:
    {
        cout << "Введите новую оценку 3 студента (0 - 5): ";
        allowedValues_i = new int[6]{0, 1, 2, 3, 4, 5};
        students[changeStud - 1].marks[2] = getInput(allowedValues_i, 6);
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        break;
    }
    }
    cout << "\nИзменение студента выполнено успешно!\n\nДля возврата в меню нажмите enter... ";
    getchar();
}

void deleteStudent(Student *&students, int &studentsNumber)
{
    if (!isStudents(studentsNumber))
        return;

    printStudentList(students, studentsNumber);

    cout << "\nУкажите номер студента, которого требуется удалить (0 - отмена операции): ";

    allowedValues_i = new int[studentsNumber + 1];

    for (int i = 0; i <= studentsNumber; i++)
        allowedValues_i[i] = i;
    int deleteStud = getInput(allowedValues_i, studentsNumber + 1);
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    if (deleteStud == 0)
    {
        cout << "\nУдаление студента прервано.\n\nДля возврата в меню нажмите enter... ";
        getchar();
        return;
    }

    Student *temp = new Student[studentsNumber - 1];
    for (int i = 0, j = 0; i < studentsNumber; i++, j++)
    {
        if (i == deleteStud)
        {
            j--;
            continue;
        }
        temp[j] = students[i];
    }

    delete[] students;
    students = temp;
    studentsNumber--;
    cout << "\nУдаление студента выполнено успешно!\n"
         << endl
         << "\nДля возврата в меню нажмите enter... ";
    getchar(); // ожидание нажатия клавиши
}

void displaySortedStudentList(Student *students, int studentsNumber)
{
    if (!isStudents(studentsNumber))
        return;
    cout << "\nВыберите тип сортировки:\n"
         << "1 - По фамилии\n"
         << "2 - По имени\n"
         << "3 - По отчеству\n"
         << "4 - По году рождения\n"
         << "5 - По курсу обучения\n"
         << "6 - По оценке\n";
    cout << "Тип сортировки: ";

    allowedValues_i = new int[6]{1, 2, 3, 4, 5, 6};
    int sortMode = getInput(allowedValues_i, 6) - 1;
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    if (sortMode == 5)
    {
        cout << "\nВведите номер оценки (1 - 3), по которой требуется сортировка: ";
        allowedValues_i = new int[3]{1, 2, 3};
        sortMode += getInput(allowedValues_i, 3) - 1;
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
    }
    cout << "\nВыберите направление сортировки:\n"
         << "1 - По убыванию\n"
         << "2 - По возрастанию\n";
    cout << "Направление сортировки: ";
    allowedValues_i = new int[2]{1, 2};
    bool descendingSort = getInput(allowedValues_i, 2) - 1;
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    sortStudentList(students, studentsNumber, sortMode, descendingSort);
    displayStudentList(students, studentsNumber);
}

void printStudentList(Student *students, int studentsNumber)
{
    cout << "--------------------------------------------------------------------------------------------------------------\n"
         << format("| {:5} | {:20} | {:20} | {:20} | {:12} | {:4} | {:7} |\n", "#", "Surname", "Name", "Patronymic", "Birth Year", "Curs", "Marks")
         << "--------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < studentsNumber; i++)
    {
        cout << format("| {:5} | {:20} | {:20} | {:20} | {:12} | {:4} | {:1}, {:1}, {:1} |\n", i + 1, students[i].surname, students[i].name, students[i].patronymic, students[i].birthYear, students[i].course, students[i].marks[0], students[i].marks[1], students[i].marks[2])
             << "--------------------------------------------------------------------------------------------------------------\n";
    }
}

void displayStudentList(Student *students, int studentsNumber)
{
    if (!isStudents(studentsNumber))
        return;
    cout << "Укажите, куда произвести вывод:\n "
         << "1 - Консоль\n "
         << "2 - Текстовый файл\n ";
    cout << "Точка вывода: ";

    allowedValues_i = new int[2]{1, 2};
    int fileOutput = getInput(allowedValues_i, 2) - 1;
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    if (fileOutput)
    {
        fstream file("output.txt", ios::out);
        file << "-------------------------------------------------------------------------------------------------------------------------\n"
             << format("| {:5} | {:20} | {:20} | {:20} | {:12} | {:4} | {:7} |\n", "№", "Фамилия", "Имя", "Отчество", "Год рождения", "Курс", "Оценки")
             << "-------------------------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < studentsNumber; i++)
        {
            file << format("| {:5} | {:20} | {:20} | {:20} | {:12} | {:4} | {:1}, {:1}, {:1} |\n", i + 1, students[i].surname, students[i].name, students[i].patronymic, students[i].birthYear, students[i].course, students[i].marks[0], students[i].marks[1], students[i].marks[2])
                 << "-------------------------------------------------------------------------------------------------------------------------\n";
        }
        cout << "\nВывод сохранен в файл\"output.txt\".\n\nДля возврата в меню нажмите enter . . . ";
    }
    else
    {
        printStudentList(students, studentsNumber);
        cout << "\nДля возврата в меню нажмите enter... ";
    }
    getchar();
}

void specifyFilePath(char *path, int binaryFile)
{
    cout << "\nУкажите файл списка студентов:\n "
         << "1 - Файл по умолчанию(" << (binaryFile ? "student_list.bin" : "student_list.txt") << ")\n "
         << "2 - Указать собственный путь\n ";
    cout << "Файл: ";
    int allowedValues_i[2] = {1, 2};
    int specifyFile = getInput(allowedValues_i, 2) - 1;

    if (specifyFile)
    {
        cout << "\nУкажите путь к файлу списка студентов: ";
        strcpy(path, getInput(1000));
    }
    else
    {
        strcpy(path, binaryFile ? "student_list.bin" : "student_list.txt");
    }
}

int importFromFile(Student *&students, int &studentsNumber, const char *path, int binaryFile)
{
    ifstream file(path, binaryFile ? ios::binary : ios::in);
    if (!file.is_open())
    {

        cout << "\nФайл списка студентов не найден. Импорт прерван.\n\nДля возврата в меню нажмите enter... ";
        getchar();
        return -1;
    }

    file.seekg(0, ios::end);
    int tempStudentsNumber = file.tellg() / (binaryFile ? sizeof(Student) : 69);
    file.seekg(0, ios::beg);
    Student *tempStudents = new Student[tempStudentsNumber];

    if (binaryFile)
    {
        for (int i = 0; i < tempStudentsNumber; i++)
            file.read((char *)&tempStudents[i], sizeof(tempStudents[i]));
    }
    else
    {
        for (int i = 0; i < tempStudentsNumber; i++)
        {
            file.read(tempStudents[i].surname, 20);
            tempStudents[i].surname[20] = '\0';

            file.read(tempStudents[i].name, 20);
            tempStudents[i].name[20] = '\0';

            file.read(tempStudents[i].patronymic, 20);
            tempStudents[i].patronymic[20] = '\0';

            char birthYear[5] = "0";
            file.read(birthYear, 4);
            tempStudents[i].birthYear = atoi(birthYear);

            char course[2] = "0";
            file.read(course, 1);
            tempStudents[i].course = atoi(course);

            char mark[2] = "0";
            file.read(mark, 1);
            tempStudents[i].marks[0] = atoi(mark);

            file.read(mark, 1);
            tempStudents[i].marks[1] = atoi(mark);

            file.read(mark, 1);
            tempStudents[i].marks[2] = atoi(mark);

            file.seekg(1, ios::cur);
        }
    }

    if (file.fail() || file.bad())
    {
        file.close();
        delete[] tempStudents;

        cout << "\nФайл списка студентов поврежден. Импорт прерван.\n\nДля возврата в меню нажмите enter... ";
        getchar();

        return -1;
    }
    file.close();

    delete[] students;
    students = tempStudents;
    studentsNumber = tempStudentsNumber;

    return 0;
}

void importStudentList(Student *&students, int &studentsNumber)
{
    if (studentsNumber != 0)
    {
        cout << "\nТекущий спискок студентов будет перезаписан. Продолжить выполнение импорта?" << endl;
        cout << "1 - Да" << endl;
        cout << "2 - Нет" << endl;
        cout << "Выбор: ";

        allowedValues_i = new int[2]{1, 2};
        int opt = getInput(allowedValues_i, 2) - 1;
        delete[] allowedValues_i;
        allowedValues_i = nullptr;

        if (opt)
            return;
    }

    int binaryFile{-1};

    cout << "Укажите тип файла для импорта списка студентов (0 - отмена операции):\n"
         << "1 - Текстовый (.txt)\n"
         << "2 - Бинарный (.bin)\n";
    cout << "Тип файла: ";
    allowedValues_i = new int[3]{0, 1, 2};
    binaryFile = getInput(allowedValues_i, 3);
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    if (binaryFile == 0)
    {
        cout << "\nИмпорт прерван.\n\nДля возврата в меню нажмите enter... ";
        getchar();
        return;
    }
    binaryFile--;

    char path[1001];

    specifyFilePath(path, binaryFile);
    importFromFile(students, studentsNumber, path, binaryFile);

    cout << "\nИмпорт выполнен успешно!\n\nДля возврата в меню нажмите enter... ";
    getchar();
}

void exportToFile(Student *&students, int &studentsNumber, const char *path, int binaryFile)
{
    ofstream file(path, binaryFile ? ios::binary : ios::out);
    if (!file.is_open())
    {

        cout << "\nФайл списка студентов не найден. Экспорт прерван.\n\nДля возврата в меню нажмите enter... ";
        getchar();
        return;
    }

    if (binaryFile)
    {
        for (int i = 0; i < studentsNumber; i++)
            file.write((char *)&students[i], sizeof(students[i]));
    }
    else
    {
        for (int i = 0; i < studentsNumber; i++)
        {
            file << setw(20) << students[i].surname;
            file << setw(20) << students[i].name;
            file << setw(20) << students[i].patronymic;
            file << setw(4) << students[i].birthYear;
            file << setw(1) << students[i].course;
            file << setw(1) << students[i].marks[0];
            file << setw(1) << students[i].marks[1];
            file << setw(1) << students[i].marks[2] << endl;
        }
    }
    file.close();
}

void exportStudentList(Student *students, int studentsNumber)
{
    if (!isStudents(studentsNumber))
        return;

    int binaryFile{-1};

    cout << "Укажите тип файла для экспорта списка студентов (0 - отмена операции):\n "
         << "1 - Текстовый (.txt)\n "
         << "2 - Бинарный (.bin)\n ";
    cout << "Тип файла: ";

    allowedValues_i = new int[3]{0, 1, 2};
    binaryFile = getInput(allowedValues_i, 3);
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    if (binaryFile == 0)
    {
        cout << "\nЭкспорт прерван.\n\nДля возврата в меню нажмите enter... ";
        getchar();
        return;
    }
    binaryFile--;

    char path[1001];

    specifyFilePath(path, binaryFile);
    exportToFile(students, studentsNumber, path, binaryFile);

    cout << "\nЭкспорт выполнен успешно!\n\nДля возврата в меню нажмите enter... ";
    getchar();
}

void transformStudentList()
{
    int tempStudentsNumber{0};
    Student *tempStudents = new Student[tempStudentsNumber];
    char path[1001];

    cout << "Укажите исходный файл списка студентов для трансформирования (0 - отмена операции):\n "
         << "1 - Файл по умолчанию (student_list.txt)\n "
         << "2 - Указать собственный путь\n ";
    cout << "Исходный файл для трансформирования: ";

    allowedValues_i = new int[3]{0, 1, 2};
    int specifyFile = getInput(allowedValues_i, 2);
    delete[] allowedValues_i;
    allowedValues_i = nullptr;

    if (specifyFile == 0)
    {
        cout << "\nТрансформирование списка студентов прервано.\n\nДля возврата в меню нажмите enter... ";
        getchar();
        delete[] tempStudents;
        return;
    }
    specifyFile--;

    if (specifyFile)
    {
        cout << "\nУкажите путь к исходному файлу списка студентов: ";
        strcpy(path, getInput(1000));
    }
    else
    {
        strcpy(path, "student_list.txt");
    }
    if (!importFromFile(tempStudents, tempStudentsNumber, path, 0))
    {
        strcpy(path, "student_list.bin");
        cout << "\nУкажите конечный файл списка студентов для трансформирования :\n "
             << "1 - Файл по умолчанию(student_list.bin)\n "
             << "2 - Указать собственный путь\n ";
        cout << "Конечный файл для трансформирования: ";
        allowedValues_i = new int[2]{1, 2};
        bool specifyFile = getInput(allowedValues_i, 2) - 1;
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        if (specifyFile)
        {
            cout << "\nУкажите путь к конечному файлу списка студентов:";
            strcpy(path, getInput(1000));
        }
        else
        {
            strcpy(path, "student_list.bin");
        }
        exportToFile(tempStudents, tempStudentsNumber, path, 1);
        cout << "\nТрансформирование списка студентов выполнено успешно !\n\nДля возврата в меню нажмите enter... ";
        getchar();
    }
    else
    {
        cout << "\nОшибка при чтении файла списка студентов. Трансформирование прервано.\n\nДля возврата в меню нажмите enter...";
        getchar();
        delete[] tempStudents;
    }
}

void swapStudents(Student &student1, Student &student2)
{
    Student tmp = student1;
    student1 = student2;
    student2 = tmp;
}

void sortByName(Student *&students, int j, bool ascendingSort)
{
    if ((ascendingSort && strcmp(students[j].name, students[j + 1].name) > 0) ||
        (!ascendingSort && strcmp(students[j].name, students[j + 1].name) < 0))
    {
        swapStudents(students[j], students[j + 1]);
    }
}

void sortBySurname(Student *&students, int j, bool ascendingSort)
{
    if ((ascendingSort && strcmp(students[j].surname, students[j + 1].surname) > 0) ||
        (!ascendingSort && strcmp(students[j].surname, students[j + 1].surname) < 0))
    {
        swapStudents(students[j], students[j + 1]);
    }
}

void sortByPatronymic(Student *&students, int j, bool ascendingSort)
{
    if ((ascendingSort && strcmp(students[j].patronymic, students[j + 1].patronymic) > 0) ||
        (!ascendingSort && strcmp(students[j].patronymic, students[j + 1].patronymic) < 0))
    {
        swapStudents(students[j], students[j + 1]);
    }
}

void sortByBirthYear(Student *&students, int j, bool ascendingSort)
{
    if ((ascendingSort && students[j].birthYear > students[j + 1].birthYear) ||
        (!ascendingSort && students[j].birthYear < students[j + 1].birthYear))
    {
        swapStudents(students[j], students[j + 1]);
    }
}

void sortByCourse(Student *&students, int j, bool ascendingSort)
{
    if ((ascendingSort && students[j].course > students[j + 1].course) ||
        (!ascendingSort && students[j].course < students[j + 1].course))
    {
        swapStudents(students[j], students[j + 1]);
    }
}

void sortByMark(Student *&students, int j, int markNumber, bool ascendingSort)
{
    if ((ascendingSort && students[j].marks[markNumber] > students[j + 1].marks[markNumber]) ||
        (!ascendingSort && students[j].marks[markNumber] < students[j + 1].marks[markNumber]))
    {
        swapStudents(students[j], students[j + 1]);
    }
}

void sortStudentList(Student *&students, int studentsNumber, int sortMode, bool ascendingSort)
{
    for (int i = 0; i < studentsNumber - 1; i++)
    {
        for (int j = 0; j < studentsNumber - 1; j++)
        {
            switch (sortMode)
            {
            case 0:
                sortBySurname(students, j, ascendingSort);
                break;
            case 1:
                sortByName(students, j, ascendingSort);
                break;
            case 2:
                sortByPatronymic(students, j, ascendingSort);
                break;
            case 3:
                sortByBirthYear(students, j, ascendingSort);
                break;
            case 4:
                sortByCourse(students, j, ascendingSort);
                break;
            case 5:
                sortByMark(students, j, 0, ascendingSort);
                break;
            case 6:
                sortByMark(students, j, 1, ascendingSort);
                break;
            case 7:
                sortByMark(students, j, 2, ascendingSort);
                break;
            }
        }
    }
}

int getInput(int *templ, int templNum)
{
    while (true)
    {
        int inp;
        cin >> inp;
        if (cin.fail())
        {
            cin.clear();
            clearInput();
            cout << "Некорректный ввод. Пожалуйста, введите правильное значение : ";
            continue;
        }
        else
        {
            clearInput();
        }

        if (templ != nullptr)
        {
            if (templNum != 0)
            {
                for (int i = 0; i < templNum; i++)
                {
                    if (inp == templ[i])
                    {
                        return inp;
                    }
                }
                cout << "Некорректный ввод. Пожалуйста, введите правильное значение : ";
            }
            else
            {
                cout << "Error: function getInput() received templNum = 0 with specified templ\n ";
                return -1;
            }
        }
        else
        {
            return inp;
        }
    }
}

char *getInput(int strLen)
{
    char *str = new char[strLen];
    cin.getline(str, strLen);
    return str;
}

bool isStudents(int studentsNumber)
{
    if (studentsNumber == 0)
    {
        cout << "\nСписок студентов пуст. Операция невозможена.\n"
             << endl
             << "Для возврата в меню нажмите enter... ";
        getchar();
        return false;
    }
    return true;
}

void printMenu()
{
    cout << "Выберите необходимое действие:\n"
         << "1 - Добавление студента\n"
         << "2 - Изменение студента\n"
         << "3 - Удаление студента\n"
         << "4 - Вывод списка студентов\n"
         << "5 - Вывод сортированного списка студентов\n"
         << "6 - Импорт списка студентов\n"
         << "7 - Экспорт списка студентов\n"
         << "8 - Трансформирование текстового файла списка студентов в бинарный\n"
         << "0 - Выход\n";
    cout << "Действие: ";
}
