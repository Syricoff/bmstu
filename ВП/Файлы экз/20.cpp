/*

Билет 20

1. Опишите структуры в с++, перечислите методы обработки полей структуры. 
2. Классифицируйте списковые структуры данных. Приведите код создания однонаправленного списка. 
3. Создайте массив символов латинских (не строка), выведите на экран. Удалите первую гласную, выведите на экран

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция для создания массива символов латинского алфавита
char* createLatinAlphabetArray(int size) {
    char* arr = new char[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 'a' + rand() % 26;  // Генерация случайной буквы латинского алфавита
    }
    return arr;
}

// Функция для удаления первой гласной буквы из массива
char* removeFirstVowel(const char* arr, int size) {
    int vowelIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            vowelIndex = i;
            break;
        }
    }
    if (vowelIndex != -1) {
        char* newArr = new char[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != vowelIndex) {
                newArr[j] = arr[i];
                j++;
            }
        }
        return newArr;
    } else {
        return NULL;  // Если гласных букв не найдено
    }
}

int main() {
    srand(time(0));  // Инициализация генератора случайных чисел

    int size = 10;
    char* alphabetArray = createLatinAlphabetArray(size);

    cout << "Исходный массив символов латинского алфавита:" << endl;
    for (int i = 0; i < size; i++) {
        cout << alphabetArray[i] << " ";
    }
    cout << endl;

    char* newArrayWithoutVowel = removeFirstVowel(alphabetArray, size);
    if (newArrayWithoutVowel != NULL) {
        cout << "Массив после удаления первой гласной буквы:" << endl;
        for (int i = 0; i < size - 1; i++) {
            cout << newArrayWithoutVowel[i] << " ";
        }
        cout << endl;
        delete[] newArrayWithoutVowel;
    } else {
        cout << "В исходном массиве нет гласных букв." << endl;
    }

    delete[] alphabetArray;

    return 0;
}
