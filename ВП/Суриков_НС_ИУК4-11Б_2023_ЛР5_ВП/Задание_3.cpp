#include <cstring>
#include <iostream>

// Функция аналогичная функции strtok()
char* STRTOK(char* str, const char* delimiters) {
    static char* nextToken = nullptr;
    // Если str != nullptr, начинаем обрабатывать новую строку
    if (str != nullptr) {
        nextToken = str;
    }
    // Если nextToken == nullptr, значит больше нет токенов
    if (nextToken == nullptr) {
        return nullptr;
    }
    // Пропускаем ведущие разделители
    while (*nextToken != '\0' && strchr(delimiters, *nextToken) != nullptr) {
        nextToken++;
    }
    // Если достигнут конец строки, значит больше нет токенов
    if (*nextToken == '\0') {
        return nullptr;
    }
    char* token = nextToken;
    // Находим конец токена
    while (*nextToken != '\0' && strchr(delimiters, *nextToken) == nullptr) {
        nextToken++;
    }
    // Если достигнут конец строки, то следующий токен - nullptr
    if (*nextToken != '\0') {
        *nextToken = '\0';
        nextToken++;
    }
    return token;
}

int main() {
    char str[100];
    std::cin.getline(str, 100);
    char delimiters[] = " ,.!"; // Разделители: пробел, запятая, точка, восклицательный знак
    char* token = STRTOK(str, delimiters);
    // Пока есть токены, выводим их на экран
    while (token != nullptr) {
        std::cout << token << std::endl;
        token = STRTOK(nullptr, delimiters);
    }
    return 0;
}
