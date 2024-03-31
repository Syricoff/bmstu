#pragma once

#include <iostream>
#include <string>
#include <functional>

using std::string;
using std::cout;

using Func = std::function<int(int)>;

namespace SNS
{
    class CMenuItem
    {
    public:
        CMenuItem() = delete; // удаление конструктора по умлчанию
        CMenuItem(string, Func); // принимающий конструктор
        CMenuItem(const CMenuItem &); // конструктор копирования
        CMenuItem & operator=(const CMenuItem &); // оператор присваивания

        int run(int) const; // запуск функции
        int operator()(size_t selected) const;

        friend std::ostream &operator<<(std::ostream &out, const CMenuItem &itemMenu);
        void print(std::ostream &out = std::cout) const;
    private:
        string m_name{};
        Func m_func{};

    };
} // namespace SNS
