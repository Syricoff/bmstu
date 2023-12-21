#include <iostream>
#include <fstream>
#include <cstring>

#include "task_1.h"

using namespace std;

void task_1()
{
    const char *filename = "res/records.bin";
    int numRecords = 0;

    createFile(filename, numRecords, false);

    int choice;
    do
    {
        printMenuTask1();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord(filename, numRecords, true);
            break;
        case 2:
            addRecord(filename, numRecords, false);
            break;
        case 3:
            swapFirstAndLastRecord(filename, numRecords);
            break;
        case 4:
            displayFile(filename, numRecords);
            break;
        case 0:
            cout << "Назад в меню" << endl;
            break;
        default:
            cout << "Направильный ввод!" << endl;
            break;
        }
        cout << endl;
    } while (choice);
}

void inputRecord(Record &record)
{
    cout << "Введите номер читательского билета: ";
    cin >> record.readerTicketNumber;

    cout << "Введите автора: ";
    cin.ignore();
    cin.getline(record.author, 50);

    cout << "Введите название: ";
    cin.getline(record.title, 50);

    cout << "Введите дату заказа: ";
    cin.getline(record.orderDate, 20);
}

void createFile(const char *filename, int &numRecords, bool byUser)
{
    ofstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cout << "Ошибка при создании файла:" << filename << endl;
        return;
    }

    numRecords = 10;
    Record *records = new Record[numRecords];

    if (byUser)
    {
        for (int i = 0; i < numRecords; i++)
        {
            cout << "Введите запись №" << i + 1 << ":" << endl;
            Record *record = new Record;
            inputRecord(*record);
            records[i] = *record;
            delete record;
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < numRecords; i++)
        {
            records[i] = {i + 1, "Author", "Title", "2023-01-01"};
        }
    }

    file.write(reinterpret_cast<char *>(records), sizeof(Record) * numRecords);
    file.close();

    delete[] records;
}

void displayFile(const char *filename, int numRecords)
{
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cout << "Ошибка при отображении файла:" << filename << endl;
        return;
    }

    Record *records = new Record[numRecords];
    file.read(reinterpret_cast<char *>(records), sizeof(Record) * numRecords);

    for (int i = 0; i < numRecords; i++)
    {
        cout << "Запись № " << i + 1 << ":" << endl;
        cout << "Номер чит.билета: " << records[i].readerTicketNumber << endl;
        cout << "Автор: " << records[i].author << endl;
        cout << "Название: " << records[i].title << endl;
        cout << "Дата заказа: " << records[i].orderDate << endl;
        cout << endl;
    }

    file.close();

    delete[] records;
}

void addRecord(const char *filename, int &numRecords, bool addToBeginning)
{
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Ошибка при открытии файла:" << filename << endl;
        return;
    }

    Record record;
    inputRecord(record);

    Record *records = new Record[++numRecords];
    file.read(reinterpret_cast<char *>(records), sizeof(Record) * (numRecords - 1));

    if (addToBeginning)
    {
        memmove(&records[1], &records[0], sizeof(Record) * (numRecords - 1));
        memcpy(&records[0], &record, sizeof(Record));
    }
    else
    {
        memcpy(&records[numRecords - 1], &record, sizeof(Record));
    }

    file.seekp(0);
    file.write(reinterpret_cast<char *>(records), sizeof(Record) * numRecords);

    file.close();

    delete[] records;
}

void swapFirstAndLastRecord(const char *filename, int numRecords)
{
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Ошибка при открытии файла:" << filename << endl;
        return;
    }

    Record *records = new Record[numRecords];
    file.read(reinterpret_cast<char *>(records), sizeof(Record) * numRecords);

    Record temp = records[0];
    records[0] = records[numRecords - 1];
    records[numRecords - 1] = temp;

    file.seekp(0);
    file.write(reinterpret_cast<char *>(records), sizeof(Record) * numRecords);

    file.close();

    delete[] records;
}

void printMenuTask1()
{
    cout << "Меню Задания 1:" << endl;
    cout << "1. Добавить запись в начало" << endl;
    cout << "2. Добавить запись в конец" << endl;
    cout << "3. Поменять местами первую и последнюю запись" << endl;
    cout << "4. Показать записи" << endl;
    cout << "0. Назад в меню" << endl;
    cout << "Выбор: ";
}
