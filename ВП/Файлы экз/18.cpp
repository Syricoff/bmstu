/*

Вп 18 билет
1. Что такое C-строки и основные операции над ними.

Строка C-style — это простой массив символов, который использует нуль-
терминатор. Нуль-терминатор — это специальный символ (ASCII-код которого
равен 0), используемый для обозначения конца строки. Строка C-style еще
называется "нуль-терминированной строкой".


2. Особенности работы с txt файлом.



3. Создать динамический массив из N эле-тов, состоящий из букв. 
Вывести его на экран. 
Удалить последний элемент. 
Вывести изменённый массив на экран

*/

#include <iostream>
#include <time.h>

char* createLatinAlphabetArray(int size) {
    char* arr = new char[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 'a' + rand() % 26;  // Генерация случайной буквы латинского алфавита
    }
    return arr;
}

void printArray(char *arr, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";}
    std::cout << std::endl;
}

char* delLastElement(char* arr, int len){
    char *newArr = new char[len - 1];
    for (int i = 0; i < len - 1; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    return newArr;
}

int main(){
    srand(time(0));  // Инициализация генератора случайных чисел
    int n{5};
    char *arr = createLatinAlphabetArray(n);
    printArray(arr, n);
    arr = delLastElement(arr, n);
    printArray(arr, n-1);
}