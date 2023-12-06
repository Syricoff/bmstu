#include <iostream>
#include <iomanip>  // для setw()
#include <curses.h> // для getchar()
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
struct Student
{
    char surname[21];
    char name[21];
    char patronymic[21];
    int birthYear;
    int course;
    int marks[3];
};
// Указатели для передачи шаблонов значений в функцию getInput
int *allowedValues_i{nullptr};
char **allowedValues_c{nullptr};
void addStudent(Student *&students, int &studentsNumber);
void changeStudent(Student *&students, int studentsNumber);
void deleteStudent(Student *&students, int &studentsNumber);
void displayStudentList(Student *students, int studentsNumber, bool silentMode = 0, bool _fileOutput = 0, int _sortMode = 0, bool _descendingSort = 0);
bool importStudentList(Student *&students, int &studentsNumber, bool silentMode = 0, bool _binaryFile = 0, const char _path[1001] = "student_list.txt");
void exportStudentList(Student *students, int studentsNumber, bool silentMode = 0, bool _binaryFile = 0, const char _path[1001] = "student_list.txt");
void transformStudentList();
// Параметр sortMode определяет поле в БД (столбец) для сортировки
void sortStudentList(Student *&students, int studentsNumber, int sortMode, bool ascendingSort);
int getInput(int *templ = nullptr, int templNum = 0);
/*
* Параметр checkMode определяет режим соответствия ввода шаблонам:
*
0 - точное совпадение с одним из шаблонов
*
1 - наличие одного из шаблонов во вводе
*/
char *getInput(int strLen, char **templ = nullptr, int templNum = 0, bool checkMode = 0);
int main()
{
    setlocale(LC_ALL, "rus");
    int studentsNumber{0};
    Student *students = new Student[studentsNumber];
    while (true)
    {
        int opt;
        cout << "Выберите необходимое действие:\n "
             << "1 - Добавление студента\n "
             << "2 - Изменение студента\n "
             << "3 - Удаление студента\n "
             << "4 - Вывод списка студентов\n "
             << "5 - Импорт списка студентов\n "
             << "6 - Экспорт списка студентов\n "
             << "7 - Трансформирование текстового файла списка студентов в бинарный\n "
             << "0 - Выход\n ";
        cout << "Действие: ";
        allowedValues_i = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        opt = getInput(allowedValues_i, 10);
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        switch (opt)
        {
        case 1:
            addStudent(students, studentsNumber);
            break;
        case 2:
            if (studentsNumber == 0)
            {
                cout << "\nСписок студентов пуст. Изменение невозможно.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
                break;
            }
            changeStudent(students, studentsNumber);
            break;
        case 3:
            if (studentsNumber == 0)
            {
                cout << "\nСписок студентов пуст. Удаление невозможно.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
                break;
            }
            deleteStudent(students, studentsNumber);
            break;
        case 4:
            if (studentsNumber == 0)
            {
                cout << "\nСписок студентов пуст. Вывод невозможен.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
                break;
            }
            displayStudentList(students, studentsNumber);
            break;
        case 5:
            if (studentsNumber != 0)
            {
                cout << "\nТекущий спискок студентов будет перезаписан. Продолжить выполнение импорта?\n "
                     << "1 - Да\n "
                     << "2 - Нет\n ";
                cout << "Выбор: ";
                allowedValues_i = new int[2]{1, 2};
                opt = getInput(allowedValues_i, 2) - 1;
                delete[] allowedValues_i;
                allowedValues_i = nullptr;
                if (opt)
                {
                    system("cls");
                    break;
                }
            }
            importStudentList(students, studentsNumber);
            break;
        case 6:
            if (studentsNumber == 0)
            {
                cout << "\nСписок студентов пуст. Экспорт невозможен.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
                break;
            }
            exportStudentList(students, studentsNumber);
            break;
        case 7:
            transformStudentList();
            break;
        case 0:
            exit(0);
        default:
            cout << "\nError: case default in main\n ";
            break;
        }
    }
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
            cout << "\nДобавление студентов прервано.\n\nДля возврата в меню нажмите enter... ";
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
        cout << "Введите оценки студента №" << i + 1 << " по 3 предметам (0 - 5) :\n"
             << "Оценка 1: ";
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
    if (studNum == 1)
        cout << "\nДобавление студента выполнено успешно!\n\nДля возврата в меню нажмите enter... ";
    else
        cout << "\nДобавление студентов выполнено успешно!\n\nДля возврата в меню нажмите enter... ";
    getchar(); // ожидание нажатия клавиши
}
void changeStudent(Student *&students, int studentsNumber)
{
    displayStudentList(students, studentsNumber, 1, 0, 0, 0);
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
    cout << "\nУкажите данные, которые требуется изменить (без пробелов):\n "
         << "1 - Фамилия\n "
         << "2 - Имя\n "
         << "3 - Отчество\n "
         << "4 - Год рождения\n "
         << "5 - Курс обучения\n "
         << "6 - Оценка 1\n "
         << "7 - Оценка 2\n "
         << "8 - Оценка 3\n ";
    cout << "Данные для изменения: ";
    char changeMode[9];
    allowedValues_c = new char *[9];
    // for (int i = 0; i < 8; i++)
    // {
    //     allowedValues_c[i] = new char[2];
    //     itoa(i, allowedValues_c[i], 10);
    // }
    strcpy(changeMode, getInput(9, allowedValues_c, 8, 1));
    delete[] allowedValues_c;
    allowedValues_c = nullptr;
    for (int i = 0; i < strlen(changeMode); i++)
    {
        if (changeMode[i] == '1')
        {
            cout << "Введите новую фамилию студента: ";
            strcpy(students[changeStud - 1].surname, getInput(21));
        }
        else if (changeMode[i] == '2')
        {
            cout << "Введите новое имя студента: ";
            strcpy(students[changeStud - 1].name, getInput(21));
        }
        else if (changeMode[i] == '3')
        {
            cout << "Введите новое отчество студента: ";
            strcpy(students[changeStud - 1].patronymic, getInput(21));
        }
        else if (changeMode[i] == '4')
        {
            cout << "Введите новый год рождения студента (1900 - 2022):";
            allowedValues_i = new int[2022 - 1900 + 1];
            for (int i = 0; i < 2022 - 1900 + 1; i++)
                allowedValues_i[i] = i + 1900;
            students[changeStud - 1].birthYear =
                getInput(allowedValues_i, 2022 - 1900 + 1);
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
        }
        else if (changeMode[i] == '5')
        {
            cout << "Введите новый курс обучения студента (1 - 6): ";
            allowedValues_i = new int[6]{1, 2, 3, 4, 5, 6};
            students[changeStud - 1].course = getInput(allowedValues_i,
                                                       6);
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
        }
        else if (changeMode[i] == '6')
        {
            cout << "Введите новую оценку 1 студента (0 - 5): ";
            allowedValues_i = new int[6]{0, 1, 2, 3, 4, 5};
            students[changeStud - 1].marks[0] =
                getInput(allowedValues_i, 6);
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
        }
        else if (changeMode[i] == '7')
        {
            cout << "Введите новую оценку 2 студента (0 - 5): ";
            allowedValues_i = new int[6]{0, 1, 2, 3, 4, 5};
            students[changeStud - 1].marks[1] =
                getInput(allowedValues_i, 6);
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
        }
        else if (changeMode[i] == '8')
        {
            cout << "Введите новую оценку 3 студента (0 - 5): ";
            allowedValues_i = new int[6]{0, 1, 2, 3, 4, 5};
            students[changeStud - 1].marks[2] =
                getInput(allowedValues_i, 6);
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
        }
    }
    cout << "\nИзменение студента выполнено успешно!\n\nДля возврата в меню нажмите enter... ";
    getchar(); // ожидание нажатия клавиши
}
void deleteStudent(Student *&students, int &studentsNumber)
{
    displayStudentList(students, studentsNumber, 1, 0, 0, 0);
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
    cout << "\nУдаление студента выполнено успешно!" << endl;
    cout << "\nДля возврата в меню нажмите enter... ";
    getchar(); // ожидание нажатия клавиши
}
void displayStudentList(Student *students, int studentsNumber, bool silentMode, bool _fileOutput, int _sortMode, bool _descendingSort)
{
    bool fileOutput = _fileOutput;
    int sortMode = _sortMode;
    bool descendingSort = _descendingSort;
    if (!silentMode)
    {
        cout << "Укажите, куда произвести вывод:\n "
             << "1 - Консоль\n "
             << "2 - Текстовый файл\n ";
        cout << "Точка вывода: ";
        allowedValues_i = new int[2]{1, 2};
        fileOutput = getInput(allowedValues_i, 2) - 1;
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        cout << "\nВыберите тип сортировки:\n "
             << "1 - По фамилии\n "
             << "2 - По имени\n "
             << "3 - По отчеству\n "
             << "4 - По году рождения\n "
             << "5 - По курсу обучения\n "
             << "6 - По оценке\n ";
        cout << "Тип сортировки: ";
        allowedValues_i = new int[6]{1, 2, 3, 4, 5, 6};
        sortMode = getInput(allowedValues_i, 6) - 1;
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
        if (sortMode == 5)
        {
            cout << "\nВведите номер оценки (1 - 3), по которой требуется сортировка : ";
            allowedValues_i = new int[3]{1, 2, 3};
            sortMode += getInput(allowedValues_i, 3) - 1;
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
        }
        cout << "\nВыберите направление сортировки:\n "
             << "1 - По возрастанию\n "
             << "2 - По убыванию\n ";
        cout << "Направление сортировки: ";
        allowedValues_i = new int[2]{1, 2};
        descendingSort = getInput(allowedValues_i, 2) - 1;
        delete[] allowedValues_i;
        allowedValues_i = nullptr;
    }
    sortStudentList(students, studentsNumber, sortMode, descendingSort);
    if (fileOutput)
    {
        fstream file("output.txt", ios::out);
        file << "----------------------------------------------------------- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -\n "
             << " | " << setw(5) << "№"
             << " | " << setw(20) << "Фамилия"
             << " | " << setw(20) << "Имя"
             << " | " << setw(20) << "Отчество"
             << " | " << setw(12) << "Год рождения"
             << " | " << setw(4) << "Курс"
             << " | " << setw(7) << "Оценки"
             << " |\n "
             << "------------------------------------------------------------- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -\n ";
        for (int i = 0; i < studentsNumber; i++)
        {
            file << "| " << setw(5) << i + 1 << " | " << setw(20) << students[i].surname << " | " << setw(20) << students[i].name << " | " << setw(20) << students[i].patronymic << " | "
                 << setw(12) << students[i].birthYear << " | " << setw(4) << students[i].course << " | " << students[i].marks[0] << ", " << students[i].marks[1] << ", " << students[i].marks[2] << " |\n";
            file << "----------------------------------------------------- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -\n ";
        }
        if (!silentMode)
            cout << "\nВывод сохранен в файл\"output.txt\".\n\nДля возврата в меню нажмите enter . . . ";
    }
    else
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------\n "
             << " | " << setw(5) << "№"
             << " | " << setw(20) << "Фамилия"
             << " | " << setw(20) << "Имя"
             << " | " << setw(20) << "Отчество"
             << " | " << setw(12) << "Год рождения"
             << " | " << setw(4) << "Курс"
             << " | " << setw(7) << "Оценки"
             << " |\n "
             << "-------------------------------------------------------------------------------------------------------------------------\n ";
        for (int i = 0; i < studentsNumber; i++)
        {
            cout << " | " << setw(5) << i + 1 
                 << " | " << setw(20 - strlen(students[i].surname)) << students[i].surname 
                 << " | " << setw(20) << students[i].name 
                 << " | " << setw(20) << students[i].patronymic 
                 << " | " << setw(12) << students[i].birthYear 
                 << " | " << setw(4) << students[i].course 
                 << " | " << students[i].marks[0] << ", " << students[i].marks[1] << ", " << students[i].marks[2] 
                 << " |\n ";
            cout << "-------------------------------------------------------------------------------------------------------------------------\n ";
        }
        if (!silentMode)
            cout << "\nДля возврата в меню нажмите enter... ";
    }
    if (!silentMode)
        getchar(); // ожидание нажатия клавиши
}
bool importStudentList(Student *&students, int &studentsNumber, bool silentMode, bool _binaryFile, const char _path[1001])
{
    int binaryFile = _binaryFile;
    if (!silentMode)
    {
        cout << "Укажите тип файла списка студентов (0 - отмена операции):\n"
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
            return 0;
        }
        binaryFile--;
    }
    if (binaryFile)
    {
        char path[1001];
        strcpy(path, _path);
        if (!silentMode)
        {
            cout << "\nУкажите файл списка студентов для импорта:\n "
                 << "1 - Файл по умолчанию(student_list.bin)\n "
                 << "2 - Указать собственный путь\n ";
            cout << "Файл для импорта: ";
            allowedValues_i = new int[2]{1, 2};
            bool specifyFile = getInput(allowedValues_i, 2) - 1;
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
            if (specifyFile)
            {
                cout << "\nУкажите путь к файлу списка студентов: ";
                strcpy(path, getInput(1000));
            }
            else
            {
                strcpy(path, "student_list.bin");
            }
        }
        fstream file(path, ios::in | ios::binary);
        if (!file.is_open())
        {
            if (!silentMode)
            {
                cout << "\nФайл списка студентов не найден. Импорт прерван.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
            }
            return 1;
        }
        file.seekg(0, ios::end);
        int tempStudentsNumber = file.tellg() / sizeof(Student);
        file.seekg(0, ios::beg);
        Student *tempStudents = new Student[tempStudentsNumber];
        for (int i = 0; i < tempStudentsNumber; i++)
            file.read((char *)&tempStudents[i], sizeof(tempStudents[i]));
        if (file.fail() || file.bad())
        {
            file.close();
            delete[] tempStudents;
            if (!silentMode)
            {
                cout << "\nФайл списка студентов поврежден. Импорт прерван.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
            }
            return 1;
        }
        file.close();
        delete[] students;
        students = tempStudents;
        studentsNumber = tempStudentsNumber;
    }
    else
    {
        char path[1001];
        strcpy(path, _path);
        if (!silentMode)
        {
            cout << "\nУкажите файл списка студентов для импорта:\n "
                 << "1 - Файл по умолчанию(student_list.txt)\n "
                 << "2 - Указать собственный путь\n ";
            cout << "Файл для импорта: ";
            allowedValues_i = new int[2]{1, 2};
            bool specifyFile = getInput(allowedValues_i, 2) - 1;
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
            if (specifyFile)
            {
                cout << "\nУкажите путь к файлу списка студентов: ";
                strcpy(path, getInput(1000));
            }
            else
            {
                strcpy(path, "student_list.txt");
            }
        }
        fstream file(path, ios::in);
        if (!file.is_open())
        {
            if (!silentMode)
            {
                cout << "\nФайл списка студентов не найден. Импорт прерван.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
            }
            return 1;
        }
        file.seekg(-1, ios::end);
        int tempStudentsNumber = file.tellg() / (20 + 20 + 20 + 4 + 1 + 3 + 1); // в скобках подсчитывается количество символов на 1 запись в БД (включая \n)
        file.seekg(0, ios::beg);
        Student *tempStudents = new Student[tempStudentsNumber];
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
            file.seekg(2, ios::cur);
        }
        if (file.fail() || file.bad())
        {
            file.close();
            delete[] tempStudents;
            if (!silentMode)
            {
                cout << "\nФайл списка студентов поврежден. Импорт прерван.\n\nДля возврата в меню нажмите enter... ";
                getchar(); // ожидание нажатия клавиши
            }
            return 1;
        }
        file.close();
        delete[] students;
        students = tempStudents;
        studentsNumber = tempStudentsNumber;
    }
    if (!silentMode)
    {
        cout << "\nИмпорт выполнен успешно!\n\nДля возврата в меню нажмите enter... ";
        getchar(); // ожидание нажатия клавиши
    }
    return 0;
}
void exportStudentList(Student *students, int studentsNumber, bool silentMode, bool _binaryFile, const char _path[1001])
{
    int binaryFile = _binaryFile;
    if (!silentMode)
    {
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
    }
    if (binaryFile)
    {
        char path[1001];
        strcpy(path, _path);
        if (!silentMode)
        {
            cout << "\nУкажите файл списка студентов для экспорта:\n "
                 << "1 - Файл по умолчанию(student_list.bin)\n "
                 << "2 - Указать собственный путь\n ";
            cout << "Файл для экспорта: ";
            allowedValues_i = new int[2]{1, 2};
            bool specifyFile = getInput(allowedValues_i, 2) - 1;
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
            if (specifyFile)
            {
                cout << "\nУкажите путь к файлу списка студентов: ";
                strcpy(path, getInput(1000));
            }
            else
            {
                strcpy(path, "student_list.bin");
            }
        }
        fstream file(path, ios::out | ios::binary);
        for (int i = 0; i < studentsNumber; i++)
            file.write((char *)&students[i], sizeof(students[i]));
        file.close();
    }
    else
    {
        char path[1001];
        strcpy(path, _path);
        if (!silentMode)
        {
            cout << "\nУкажите файл списка студентов для эскпорта:\n "
                 << "1 - Файл по умолчанию(student_list.txt)\n "
                 << "2 - Указать собственный путь\n ";
            cout << "Файл для экспорта: ";
            allowedValues_i = new int[2]{1, 2};
            bool specifyFile = getInput(allowedValues_i, 2) - 1;
            delete[] allowedValues_i;
            allowedValues_i = nullptr;
            if (specifyFile)
            {
                cout << "\nУкажите путь к файлу списка студентов: ";
                strcpy(path, getInput(1000));
            }
            else
            {
                strcpy(path, "student_list.txt");
            }
        }
        fstream file(path, ios::out);
        for (int i = 0; i < studentsNumber; i++)
        {
            file << setw(20) << students[i].surname << setw(20) << students[i].name << setw(20) << students[i].patronymic << setw(4) << students[i].birthYear << setw(1) << students[i].course << setw(1) << students[i].marks[0] << setw(1) << students[i].marks[1] << setw(1) << students[i].marks[2] << '\n';
        }
        file.close();
    }
    if (!silentMode)
    {
        cout << "\nЭкспорт выполнен успешно!\n\nДля возврата в меню нажмите enter... ";
        getchar(); // ожидание нажатия клавиши
    }
}
void transformStudentList()
{
    int tempStudentsNumber{0};
    Student *tempStudents = new Student[tempStudentsNumber];
    char path[1001] = "student_list.txt";
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
        return;
    }
    specifyFile--;
    if (specifyFile)
    {
        cout << "\nУкажите путь к исходному файлу списка студентов: ";
        strcpy(path, getInput(1000));
    }
    if (!importStudentList(tempStudents, tempStudentsNumber, 1, 0, path))
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
        exportStudentList(tempStudents, tempStudentsNumber, 1, 1, path);
        cout << "\nТрансформирование списка студентов выполнено успешно !\n\nДля возврата в меню нажмите enter... ";
        getchar(); // ожидание нажатия клавиши
    }
    else
    {
        cout << "\nОшибка при чтении файла списка студентов. Трансформирование прервано.\n\nДля возврата в меню нажмите enter...";
        getchar(); // ожидание нажатия клавиши
    }
}
void sortStudentList(Student *&students, int studentsNumber, int sortMode, bool ascendingSort)
{
    for (int i = 0; i < studentsNumber - 1; i++)
    {
        for (int j = 0; j < studentsNumber - 1; j++)
        {
            switch (ascendingSort)
            {
            case 0:
            default:
                switch (sortMode)
                {
                default:
                case 0:
                    for (int k = 0; k <
                                    max(strlen(students[j].surname), strlen(students[j + 1].surname));
                         k++)
                    {
                        if (students[j].surname[k] > students[j +
                                                              1]
                                                         .surname[k])
                        {
                            Student tmp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = tmp;
                            break;
                        }
                        else if (students[j].surname[k] <
                                 students[j + 1].surname[k])
                        {
                            break;
                        }
                    }
                    break;
                case 1:
                    for (int k = 0; k <
                                    max(strlen(students[j].name), strlen(students[j + 1].name));
                         k++)
                    {
                        if (students[j].name[k] > students[j +
                                                           1]
                                                      .name[k])
                        {
                            Student tmp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = tmp;
                            break;
                        }
                        else if (students[j].name[k] < students[j + 1].name[k])
                        {
                            break;
                        }
                    }
                    break;
                case 2:
                    for (int k = 0; k <
                                    max(strlen(students[j].patronymic), strlen(students[j + 1].patronymic));
                         k++)
                    {
                        if (students[j].patronymic[k] > students[j + 1].patronymic[k])
                        {
                            Student tmp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = tmp;
                            break;
                        }
                        else if (students[j].patronymic[k] <
                                 students[j + 1].patronymic[k])
                        {
                            break;
                        }
                    }
                    break;
                case 3:
                    if (students[j].birthYear > students[j +
                                                         1]
                                                    .birthYear)
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 4:
                    if (students[j].course > students[j + 1].course)
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 5:
                    if (students[j].marks[0] > students[j +
                                                        1]
                                                   .marks[0])
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 6:
                    if (students[j].marks[1] > students[j +
                                                        1]
                                                   .marks[1])
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 7:
                    if (students[j].marks[2] > students[j +
                                                        1]
                                                   .marks[2])
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                }
                break;
            case 1:
                switch (sortMode)
                {
                default:
                case 0:
                    for (int k = 0; k <
                                    max(strlen(students[j].surname), strlen(students[j + 1].surname));
                         k++)
                    {
                        if (students[j].surname[k] < students[j +
                                                              1]
                                                         .surname[k])
                        {
                            Student tmp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = tmp;
                            break;
                        }
                        else if (students[j].surname[k] >
                                 students[j + 1].surname[k])
                        {
                            break;
                        }
                    }
                    break;
                case 1:
                    for (int k = 0; k <
                                    max(strlen(students[j].name), strlen(students[j + 1].name));
                         k++)
                    {
                        if (students[j].name[k] < students[j +
                                                           1]
                                                      .name[k])
                        {
                            Student tmp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = tmp;
                            break;
                        }
                        else if (students[j].name[k] > students[j + 1].name[k])
                        {
                            break;
                        }
                    }
                    break;
                case 2:
                    for (int k = 0; k <
                                    max(strlen(students[j].patronymic), strlen(students[j + 1].patronymic));
                         k++)
                    {
                        if (students[j].patronymic[k] < students[j + 1].patronymic[k])
                        {
                            Student tmp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = tmp;
                            break;
                        }
                        else if (students[j].patronymic[k] >
                                 students[j + 1].patronymic[k])
                        {
                            break;
                        }
                    }
                    break;
                case 3:
                    if (students[j].birthYear < students[j +
                                                         1]
                                                    .birthYear)
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 4:
                    if (students[j].course < students[j + 1].course)
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 5:
                    if (students[j].marks[0] < students[j +
                                                        1]
                                                   .marks[0])
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 6:
                    if (students[j].marks[1] < students[j +
                                                        1]
                                                   .marks[1])
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                case 7:
                    if (students[j].marks[2] < students[j +
                                                        1]
                                                   .marks[2])
                    {
                        Student tmp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = tmp;
                    }
                    break;
                }
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
            while (cin.peek() != '\n')
                cin.ignore();
            cout << "Некорректный ввод. Пожалуйста, введите правильное значение : ";
            continue;
        }
        else
        {
            while (cin.get() != '\n')
                ;
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
char *getInput(int strLen, char **templ, int templNum, bool checkMode)
{
    while (true)
    {
        char *inp = new char[strLen];
        cin >> setw(strLen) >> inp;
        while (cin.peek() != '\n')
            cin.ignore();
        if (templ != nullptr)
        {
            if (templNum != 0)
            {
                for (int i = 0; i < templNum; i++)
                {
                    if (checkMode)
                    {
                        if (strstr(inp, templ[i]) != 0)
                            return inp;
                    }
                    else
                    {
                        if (!strcmp(inp, templ[i]))
                            return inp;
                    }
                }
                cout << "Некорректный ввод. Пожалуйста, введите правильное значение : ";
            }
            else
            {
                delete[] inp;
                cout << "Error: function getInput() received templNum = 0 with specified templ\n ";
                return " ";
            }
        }
        else
        {
            return inp;
        }
    }
}