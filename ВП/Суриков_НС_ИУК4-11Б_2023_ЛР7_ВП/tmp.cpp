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
    HISTORY
};

struct Student
{
    char surname[20];
    int group;
    float average;
    bool disciplines[5];
};

void printDiscipline(Discipline discipline)
{
    switch (discipline)
    {
    case MATH:
        cout << "Mathematics";
        break;
    case PHYSICS:
        cout << "Physics";
        break;
    case CHEMISTRY:
        cout << "Chemistry";
        break;
    case BIOLOGY:
        cout << "Biology";
        break;
    case HISTORY:
        cout << "History";
        break;
    }
}

void printStudent(Student student)
{
    cout << "Surname: " << student.surname << endl;
    cout << "Group: " << student.group << endl;
    cout << "Average score: " << student.average << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "- ";
        printDiscipline((Discipline)i);
        cout << ": ";
        if (student.disciplines[i])
        {
            cout << "*";
        }
        else
        {
            cout << "-";
        }
        cout << endl;
    }
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
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

void readStudents(Student students[], int count, const char *filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        count = 0;
        while (!file.eof())
        {
            file >> students[count].surname;
            file >> students[count].group;
            file >> students[count].average;
            for (int i = 0; i < 5; i++)
            {
                char c;
                file >> c;
                if (c == '*')
                {
                    students[count].disciplines[i] = true;
                }
                else
                {
                    students[count].disciplines[i] = false;
                }
            }
            count++;
        }
        count--;
        file.close();
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

void printStudents(Student students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printStudent(students[i]);
        cout << endl;
    }
}

void writeDisciplineStudents(Student students[], int count, const char *filename, Discipline discipline)
{
    ofstream file(filename);
    if (file.is_open())
    {
        int disciplineCount = 0;
        for (int i = 0; i < count; i++)
        {
            if (students[i].disciplines[discipline])
            {
                file << students[i].surname << " ";
                file << students[i].group << " ";
                file << students[i].average << endl;
                disciplineCount++;
            }
        }
        if (disciplineCount > 10)
        {
            Student disciplineStudents[disciplineCount];
            int disciplineStudentCount = 0;
            for (int i = 0; i < count; i++)
            {
                if (students[i].disciplines[discipline])
                {
                    disciplineStudents[disciplineStudentCount] = students[i];
                    disciplineStudentCount++;
                }
            }
            for (int i = 0; i < disciplineCount - 1; i++)
            {
                for (int j = i + 1; j < disciplineCount; j++)
                {
                    if (disciplineStudents[j].average > disciplineStudents[i].average)
                    {
                        Student temp = disciplineStudents[i];
                        disciplineStudents[i] = disciplineStudents[j];
                        disciplineStudents[j] = temp;
                    }
                }
            }
            file << "Top 10 students by average score:" << endl;
            for (int i = 0; i < 10; i++)
            {
                file << disciplineStudents[i].surname << " ";
                file << disciplineStudents[i].group << " ";
                file << disciplineStudents[i].average << endl;
            }
        file.close();
        }
        else
        {
            cout << "Unable to open file: " << filename << endl;
        }
    }
}

int main()
{
    const char *filename = "students.txt";
    const char *mathFilename = "math_students.txt";
    const char *physicsFilename = "physics_students.txt";
    const char *chemistryFilename = "chemistry_students.txt";
    const char *biologyFilename = "biology_students.txt";
    const char *historyFilename = "history_students.txt";

    Student students[3];
    students[0] = {"Ivanov", 1, 4.5, true, false, true, false, true};
    students[1] = {"Petrov", 2, 3.8, false, true, true, false, false};
    students[2] = {"Sidorov", 1, 4.2, true, true, false, true, false};

    writeStudents(students, 3, filename);

    int count;
    Student readStudentsArray[10];
    readStudents(readStudentsArray, count, filename);

    cout << "All students:" << endl;
    printStudents(readStudentsArray, count);

    writeDisciplineStudents(readStudentsArray, count, mathFilename, MATH);
    writeDisciplineStudents(readStudentsArray, count, physicsFilename, PHYSICS);
    writeDisciplineStudents(readStudentsArray, count, chemistryFilename, CHEMISTRY);
    writeDisciplineStudents(readStudentsArray, count, biologyFilename, BIOLOGY);
    writeDisciplineStudents(readStudentsArray, count, historyFilename, HISTORY);

    return 0;
}