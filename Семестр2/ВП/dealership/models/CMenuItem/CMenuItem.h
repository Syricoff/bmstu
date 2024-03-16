#pragma once

#include <iostream>


namespace SNS
{
    class CMenuItem
    {
    public:
        typedef int (*Func)();
        CMenuItem(std::string, Func);
        Func func{};
        std::string item_name{};
        std::string getName();
        void print();
        int run();
    };
} // namespace SNS
