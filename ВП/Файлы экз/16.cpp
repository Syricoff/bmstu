/*

Билет 16
1. Опишите понятие указатель на данное и перечислите основные приёмы работы с ними.

2. Проиллюстрируйте работу пользовательской функции, принимающей в качестве параметра двумерный массив.

3. Дана С-строка, состоящая из слов, разделённых пробелами. Вставить «*» перед каждым словом. 
Вывести изменённую строку на экран.

*/

#include <iostream>
#include <cstring>

void insertStars(char* input, char* output) {
    char* token = std::strtok(input, " ");
    while (token != nullptr) {
        std::strcat(output, "*");
        std::strcat(output, token);
        token = std::strtok(nullptr, " ");
    }
}

int main() {
    char inputString[1000];
    std::cout << "Введите строку: ";
    std::cin.getline(inputString, sizeof(inputString));

    char result[2000] = "";
    insertStars(inputString, result);

    std::cout << "Измененная строка: " << result << std::endl;

    return 0;
}
