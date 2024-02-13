#ifndef TASK_1_H
#define TASK_1_H

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

Student *generateRandomStudents(int count);
void writeStudents(Student students[], int count, const char *filename);
void readStudents(Student students[], int count, const char *filename);
void sortStudentsByAverage(Student students[], int count);
void writeDisciplineStudents(Student students[], int count, const char *filename, Discipline discipline);
void task_1();


#endif // TASK_1_H