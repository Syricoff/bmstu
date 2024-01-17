/*

22 билет
1. что то про сегментацию данных в оперативной памяти при размещении переменных
2. привести пример совместного использования указателя и константы
3. дан текстовый файл со строками. в каждой строке удалить символ точки (.), 
в новый текстовый файл записать измененные строки и количество удаленных символов

*/

#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    char line[100]; // Предположим, что максимальная длина строки - 100 символов
    int removedCharsCount = 0;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (inputFile.getline(line, 100)) {
            for (int i = 0; i < strlen(line); i++) {
                if (line[i] == '.') {
                    for (int j = i; j < strlen(line); j++) {
                        line[j] = line[j + 1]; // Удаляем символ точки путем сдвига оставшейся части строки
                    }
                    removedCharsCount++;
                }
            }
            outputFile << line << std::endl;
        }
        inputFile.close();
        outputFile.close();

        std::ofstream countFile("count.txt");
        countFile << "Количество удаленных символов: " << removedCharsCount << std::endl;
        countFile.close();
    } else {
        std::cout << "Невозможно открыть файлы" << std::endl;
    }

    return 0;
}
