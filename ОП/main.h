#ifndef MAIN_H
#define MAIN_H

struct Student
{
    char surname[21];
    char name[21];
    char patronymic[21];
    int birthYear;
    int course;
    int marks[3];
};

// Указатель для передачи шаблонов значений в функцию getInput
int *allowedValues_i{nullptr};

// Функция для импорта данных студентов из файла
int importFromFile(Student *&students, int &studentsNumber, const char *path, int binaryFile);

// Функция для экспорта данных студентов в файл
void exportToFile(Student *&students, int &studentsNumber, const char *path, int binaryFile);

// Функции для отображения списка студентов
void displayStudentList(Student *students, int studentsNumber); // Отображает список студентов в консоли
void printStudentList(Student *students, int studentsNumber); // Печатает список студентов
void displaySortedStudentList(Student *students, int studentsNumber); // Отображает отсортированный список студентов

// Функция для сортировки списка студентов
void sortStudentList(Student *&students, int studentsNumber, int sortMode, bool descendingSort);

// Функция для указания пути к файлу
void specifyFilePath(char *path, int binaryFile);

// Функция для получения ввода от пользователя
int getInput(int *templ = nullptr, int templNum = 0); // Получает целочисленный ввод от пользователя
char *getInput(int strLen); // Получает строковый ввод от пользователя

// Функция для обмена местами двух студентов
void swapStudents(Student &a, Student &b);

// Функции для сортировки студентов по различным критериям
void sortByName(Student *&students, int j, bool ascendingSort);
void sortByPatronymic(Student *&students, int j, bool ascendingSort);
void sortByBirthYear(Student *&students, int j, bool ascendingSort);
void sortByCourse(Student *&students, int j, bool ascendingSort);
void sortByMark(Student *&students, int j, bool ascendingSort, int markNumber);

// Функции для добавления, изменения и удаления студента
void addStudent(Student *&students, int &studentsNumber);
void changeStudent(Student *&students, int studentsNumber);
void deleteStudent(Student *&students, int &studentsNumber);

// Функции для импорта и экспорта списка студентов
void importStudentList(Student *&students, int &studentsNumber);
void exportStudentList(Student *students, int studentsNumber);

// Функция для проверки, есть ли студенты в списке
bool isStudents(int studentsNumber);

// Функция для преобразования списка студентов
void transformStudentList();

// Функции для очистки ввода и вывода
void clearInput(); // Очищает ввод пользователя
void clearDisplay(); // Очищает консоль

// Функция для отображения меню
void printMenu();

#endif // MAIN_H