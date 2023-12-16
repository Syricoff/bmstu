#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "task_1.h"

using namespace std;

Student *generateRandomStudents(int count)
{
    srand(time(nullptr));

    Student *students = new Student[count];

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            students[i].surname[j] = 'A' + rand() % 26;
        }
        students[i].surname[19] = '\0';

        students[i].group = rand() % 10 + 1;

        students[i].average = static_cast<float>(rand() % 51) / 10;

        for (int j = 0; j < 5; j++)
        {
            students[i].disciplines[j] = rand() % 2 == 0;
        }
    }

    return students;
}

void writeStudents(Student students[], int count, const char *filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < count; i++)
        {
            file << students[i].surname << " ";
            file << students[i].group << " ";
            file << students[i].average << " ";
            for (int j = 0; j < 5; j++)
            {
                if (students[i].disciplines[j])
                {
                    file << "*";
                }
                else
                {
                    file << "-";
                }
            }
            file << endl;
        }
        file.close();
        cout << "Данные записаны в файл: " << filename << endl;
    }
    else
    {
        cout << "Невозможно открыть файл: " << filename << endl;
    }
}

void readStudents(Student students[], int count, const char *filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < count; i++)
        {
            char line[256];
            file.getline(line, 256);

            char *token = strtok(line, " ");
            strcpy(students[i].surname, token);

            token = strtok(nullptr, " ");
            students[i].group = atoi(token);

            token = strtok(nullptr, " ");
            students[i].average = atof(token);

            token = strtok(nullptr, " ");
            for (int j = 0; j < 5; j++)
            {
                if (token[j] == '*')
                {
                    students[i].disciplines[j] = true;
                }
                else
                {
                    students[i].disciplines[j] = false;
                }
            }
        }
        file.close();
    }
    else
    {
        cout << "Невозможно открыть файл: " << filename << endl;
    }
}

void sortStudentsByAverage(Student students[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].average < students[j + 1].average)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void writeDisciplineStudents(Student students[], int count, char *filename, Discipline discipline)
{
    int disciplineCount = 0;
    for (int i = 0; i < count; i++)
    {
        if (students[i].disciplines[discipline])
        {
            disciplineCount++;
        }
    }

    Student disciplineStudents[disciplineCount];
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        if (students[i].disciplines[discipline])
        {
            disciplineStudents[j] = students[i];
            j++;
        }
    }

    if (disciplineCount > 10)
    {
        sortStudentsByAverage(disciplineStudents, disciplineCount);
        writeStudents(disciplineStudents, 10, filename);
    }
    else
    {
        writeStudents(disciplineStudents, disciplineCount, filename);
    }
}

void task_1()
{
    const char *filename = "res/students.txt";

    int count{20};

    // Student *students = generateRandomStudents(count);
    Student students[count] = {
        {"Ivanov", 1, 4.5, {true, false, true, false, true}},
        {"Petrov", 2, 3.8, {false, true, false, true, false}},
        {"Sidorov", 1, 4.2, {true, true, true, true, true}},
        {"Smith", 3, 3.5, {false, false, false, false, false}},
        {"Johnson", 2, 4.0, {true, true, false, false, true}},
        {"Brown", 1, 3.9, {false, true, true, false, false}},
        {"Lee", 3, 4.1, {true, false, true, false, true}},
        {"Kim", 2, 3.7, {false, true, false, true, false}},
        {"Garcia", 1, 4.4, {true, true, true, true, true}},
        {"Martinez", 2, 3.6, {false, false, false, false, false}},
        {"Lopez", 1, 4.3, {true, true, false, false, true}},
        {"Liu", 3, 3.9, {false, true, true, false, false}},
        {"Wang", 2, 4.2, {true, false, true, false, true}},
        {"Gonzalez", 1, 3.8, {false, true, false, true, false}},
        {"Hernandez", 3, 4.0, {true, true, true, true, true}},
        {"Taylor", 2, 3.5, {false, false, false, false, false}},
        {"Anderson", 1, 4.1, {true, true, false, false, true}},
        {"Thomas", 3, 3.7, {false, true, false, true, false}},
        {"Jackson", 1, 4.4, {true, true, true, true, true}},
        {"White", 2, 3.6, {false, false, false, false, false}}};

    writeStudents(students, count, filename);

    Student readStudentsArray[count];
    readStudents(readStudentsArray, count, filename);

    int choice;
    cout << "Выберите дисциплину: " << endl;
    cout << "1. Математика" << endl;
    cout << "2. Физика" << endl;
    cout << "3. Химия" << endl;
    cout << "4. Биология" << endl;
    cout << "5. История" << endl;
    cout << "Введите номер предмета: ";
    cin >> choice;

    char disciplineOutFilename[256];
    cout << "Введите путь к файлу для записи данных: ";
    cin >> disciplineOutFilename;

    if (choice - 1 <= HISTORY && choice - 1 >= MATH)
    {
        writeDisciplineStudents(students, count, disciplineOutFilename, (Discipline)(choice - 1));
    }
    else
    {
        cout << "Введено неверное значение" << endl;
    }
}