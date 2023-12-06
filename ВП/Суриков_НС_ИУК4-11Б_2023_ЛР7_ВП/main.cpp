#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum Discipline
{
    MATH,
    PHYSICS,
    CHEMISTRY,
    BIOLOGY,
    COMPUTER_SCIENCE
};

struct Student
{
    char lastName[50];
    int groupNumber;
    double averageScore;
    char chosenDisciplines[6];
};

void writeToFile(Student *students, int count)
{
    std::ofstream file("students.txt");
    for (int i = 0; i < count; i++)
    {
        file << students[i].lastName << " " << students[i].groupNumber << " " << students[i].averageScore << " ";
        file << students[i].chosenDisciplines << std::endl;
    }
    file.close();
}

void filterByDisciplineAndScore(const char *discipline, double scoreThreshold)
{
    std::ifstream file("students.txt");
    if (file.is_open())
    {
        Student student;
        while (file >> student.lastName >> student.groupNumber >> student.averageScore >> student.chosenDisciplines)
        {
            if (std::strstr(student.chosenDisciplines, discipline) != nullptr && student.averageScore > scoreThreshold)
            {
                std::cout << "Last Name: " << student.lastName << std::endl;
                std::cout << "Group Number: " << student.groupNumber << std::endl;
                std::cout << "Average Score: " << student.averageScore << std::endl;
                std::cout << "Chosen Disciplines: " << student.chosenDisciplines << std::endl;
                std::cout << std::endl;
            }
        }
        file.close();
    }
}

int main()
{
    // Создание файла со сведениями о студентах
    Student students[100];

    strcpy(students[0].lastName, "Иванов");
    students[0].groupNumber = 1;
    students[0].averageScore = 4.5;
    strcpy(students[0].chosenDisciplines, "A*B*C");

    strcpy(students[1].lastName, "Петров");
    students[1].groupNumber = 2;
    students[1].averageScore = 3.8;
    strcpy(students[1].chosenDisciplines, "*BCD");

    strcpy(students[2].lastName, "Сидоров");
    students[2].groupNumber = 1;
    students[2].averageScore = 4.2;
    strcpy(students[2].chosenDisciplines, "*AB*");

    strcpy(students[3].lastName, "Смирнов");
    students[3].groupNumber = 3;
    students[3].averageScore = 4.9;
    strcpy(students[3].chosenDisciplines, "*BCD");

    strcpy(students[4].lastName, "Козлов");
    students[4].groupNumber = 2;
    students[4].averageScore = 3.5;
    strcpy(students[4].chosenDisciplines, "*CDE");

    int lentght = sizeof(students) / sizeof(students[0]);

    writeToFile(students, lentght);

    // Фильтрация студентов по дисциплине и среднему баллу
    filterByDisciplineAndScore("BCD", 4.0);

    return 0;
}

// void printMenu();

// void task1()
// {
// }

// void task2()
// {
// }

// int main()
// {
//     int choice;

//     do
//     {
//         printMenu();
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             task1();
//             break;
//         case 2:
//             task2();
//             break;
//         case 0:
//             cout << "Выход из программы." << endl;
//             break;
//         default:
//             cout << "Некорректный выбор. Попробуйте еще раз." << endl;
//             break;
//         }

//         cout << endl;

//     } while (choice != 0);
// }

// void printMenu()
// {
//     cout << "Меню:" << endl;
//     cout << "1. Задание 1" << endl;
//     cout << "2. Задание 2" << endl;
//     cout << "0. Выход" << std::endl;
//     cout << "Выберите номер задания: ";
// }
