#pragma once

#include <functional>
#include <iostream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::string;

namespace SNS
{
    // интерфейс для валидирования ввода строки
    using ValidateString = std::function<bool(string)>;
    // интерфейс для валидирования ввода числа
    using ValidateNum = std::function<bool(int)>;
    // интерфейс для валидирвоания ввода символа
    using ValidateChar = std::function<bool(char)>;

    // функция считывнаия строки с консоли
    string getEnteredString(string text, ValidateString validate = nullptr, std::istream &in = cin);
    // функция считывнаия числа с консоли
    int getEnteredNum(string text, ValidateNum validate = nullptr, std::istream &in = cin);
    // функция считывнаия символа с консоли
    char getEnteredChar(string text, ValidateChar validate = nullptr, std::istream &in = cin);

} // namespace SNS
