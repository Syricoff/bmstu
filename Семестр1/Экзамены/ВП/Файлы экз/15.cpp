/*

Билет 15

1. Опишите понятие двумерного массива и представление их в памяти компьютера.

2. Покажите на примере, почему бинарные файлы по-другому называются файлами произвольного доступа.

3. В текстовом файле найдите и удалите все слова, начинающиеся и заканчивающиеся одной и той же буквой.

*/

#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    char word[100]; // Максимальная длина слова
    char ch;
    bool shouldRemove;
    int removedWordsCount = 0;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (inputFile >> word) {
            shouldRemove = true;
            int len = strlen(word);
            if (len > 1 && word[0] == word[len - 1]) {
                shouldRemove = false;
                removedWordsCount++;
            }
            if (!shouldRemove) {
                outputFile << word << " ";
            }
        }
        inputFile.close();
        outputFile.close();

        std::cout << "Количество удаленных слов: " << removedWordsCount << std::endl;
    } else {
        std::cout << "Невозможно открыть файлы" << std::endl;
    }

    return 0;
}
