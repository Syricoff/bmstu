#include <iostream>
#include <fstream>
#include <cstring>

#include "task_2.h"

using namespace std;

void task_2()
{
    const char *textFilePath = "res/file.txt";
    const char *recordFilePath = "res/file.bin";

    int choice;
    do
    {
        printMenuTask2();
        cin >> choice;
        switch (choice)
        {
        case 1:
            createRecordFile(textFilePath, recordFilePath);
            break;
        case 2:
            printRecordFile(recordFilePath);
            break;
        case 3:
            swapRecords(recordFilePath);
            break;
        case 0:
            cout << "Назад в меню" << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);
}

void createRecordFile(const char *textFilePath, const char *recordFilePath)
{
    ifstream textFile(textFilePath);
    ofstream recordFile(recordFilePath, ios::binary);

    if (!textFile.is_open() || !recordFile.is_open())
    {
        cout << "Не удалось открыть файл." << endl;
        return;
    }

    char line[MAX_LINE_LENGTH];

    do
    {
        streampos linePos = textFile.tellg();
        recordFile.write(reinterpret_cast<const char *>(&linePos), sizeof(streampos));
    } while (textFile.getline(line, MAX_LINE_LENGTH));

    textFile.close();
    recordFile.close();

    cout << "Файл записей создан." << endl;
}

void swapRecords(const char *recordFilePath)
{
    fstream recordFile(recordFilePath, ios::binary | ios::in | ios::out);

    if (!recordFile.is_open())
    {
        cout << "Не удалось открыть файл записей." << endl;
        return;
    }

    int recordIndex1, recordIndex2;
    cout << "Введите индексы записей для обмена: ";
    cin >> recordIndex1 >> recordIndex2;

    streampos recordPos1 = recordIndex1 * sizeof(streampos);
    streampos recordPos2 = recordIndex2 * sizeof(streampos);

    recordFile.seekg(recordPos1);
    streampos linePos1;
    recordFile.read(reinterpret_cast<char *>(&linePos1), sizeof(streampos));

    recordFile.seekg(recordPos2);
    streampos linePos2;
    recordFile.read(reinterpret_cast<char *>(&linePos2), sizeof(streampos));

    recordFile.seekp(recordPos1);
    recordFile.write(reinterpret_cast<const char *>(&linePos2), sizeof(streampos));

    recordFile.seekp(recordPos2);
    recordFile.write(reinterpret_cast<const char *>(&linePos1), sizeof(streampos));

    recordFile.close();

    cout << "Записи поменяны местами." << endl;
}

void printRecordFile(const char *recordFilePath)
{
    ifstream recordFile(recordFilePath, ios::binary);

    if (!recordFile.is_open())
    {
        cout << "Не удалось открыть файл записей." << endl;
        return;
    }

    streampos linePos;
    while (recordFile.read(reinterpret_cast<char *>(&linePos), sizeof(streampos)))
    {
        ifstream textFile("res/file.txt");
        if (!textFile.is_open())
        {
            cout << "Не удалось открыть текстовый файл." << endl;
            return;
        }

        textFile.seekg(linePos);
        char line[MAX_LINE_LENGTH];
        if (textFile.getline(line, MAX_LINE_LENGTH))
        {
            cout << line << endl;
        }

        textFile.close();
    }

    recordFile.close();
}

void printMenuTask2()
{
    cout << "Меню:" << endl;
    cout << "1. Создать файл записей" << endl;
    cout << "2. Вывести файл записей" << endl;
    cout << "3. Обменять записи местами" << endl;
    cout << "0. Назад в меню" << endl;
    cout << "Введите выбор: ";
}
