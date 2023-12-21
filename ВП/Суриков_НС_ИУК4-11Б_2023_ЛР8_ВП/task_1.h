#ifndef TASK_1_H
#define TASK_1_H

struct Record
{
    int readerTicketNumber;
    char author[50];
    char title[50];
    char orderDate[20];
};

void inputRecord(Record &record);
void createFile(const char *filename, int &numRecords, bool byUser);
void displayFile(const char *filename, int numRecords);
void addRecord(const char *filename, int &numRecords, bool addToBeginning);
void swapFirstAndLastRecord(const char *filename, int numRecords);
void printMenuTask1();
void task_1();

#endif // TASK_1_H