#ifndef TASK_2_H
#define TASK_2_H

const int MAX_LINE_LENGTH = 256;
void createRecordFile(const char *textFilePath, const char *recordFilePath);
void swapRecords(const char *recordFilePath);
void printRecordFile(const char *recordFilePath);
void printMenuTask2();
void task_2();

#endif // TASK_2_H