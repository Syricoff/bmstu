#include <iostream>
#include <fstream>
#include <cstring>


/* 

1. Понятие ссылки. Методы работы с ними.
2. Пример механизма возврата двумерного массива из функции.
3. Дан текстовый файл со строкой. Из строки удалить повторяющиеся буквы.

 */


void delDubl(char *inputString)
{
    int len = strlen(inputString);
    int currentIndex = 0;

    for (int i = 0; i < len; i++)
    {
        if (strchr(inputString, inputString[i]) == &inputString[i])
        {
            inputString[currentIndex++] = inputString[i];
        }
    }
    inputString[currentIndex] = '\0';
}


int main()
{
    std::ifstream inFile("input.txt");
    char inputString[1000];

    if (inFile.is_open())
    {
        inFile.getline(inputString, 1000);
        inFile.close();

        delDubl(inputString);

        std::cout << inputString << std::endl;
    }
    else
    {
        std::cerr << "Не удалось открыть файл для чтения" << std::endl;
        return 1;
    }

    return 0;
}