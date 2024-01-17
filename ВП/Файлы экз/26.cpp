/*

1) Что такое функция и способы её вызова.
2) Напишите подпрограмму для поиска элемента по значению в одностороннем списке (читай как дин. массив).
3) В текстовом файле находятся слова, разделённые пробелами. 
Заменить в каждом слове все "а" на "о", 
посчитать кол-во замен и 
вывести результат вместе с изменёнными строками в другой текстовый файл.

1. Функция - именованный блок кода, который выполняет определенную задачу. Существует несколько способов вызова функции:
   - Вызов по имени: просто указывается имя функции, за которым следуют скобки.
   - Вызов через указатель на функцию: указатель на функцию используется для вызова функции, на которую он указывает.
   - Рекурсивный вызов: функция вызывает саму себя.

2. Вот пример подпрограммы на C++ для поиска элемента по значению в динамическом массиве:

#include <iostream>

int findElement(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i; // Возвращаем индекс элемента, если он найден
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

int main() {
    int size = 5;
    int* dynamicArray = new int[size] {2, 4, 6, 8, 10};
    int valueToFind = 6;
    int index = findElement(dynamicArray, size, valueToFind);
    if (index != -1) {
        std::cout << "Элемент найден по индексу: " << index << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }
    delete[] dynamicArray; // Не забудьте освободить память
    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файлов" << std::endl;
        return 1;
    }

    std::string word;
    int replacementsCount = 0;

    while (inputFile >> word) {
        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == 'a') {
                word[i] = 'o';
                replacementsCount++;
            }
        }
        outputFile << word << " ";
    }

    std::cout << "Количество замен: " << replacementsCount << std::endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
