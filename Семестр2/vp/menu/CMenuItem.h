#pragma once

#include <iostream>
#include <string>

using namespace std;


 class CMenuItem {
    public:
        typedef int (*Func)();
        CMenuItem(string, Func);
        Func func{};
        string item_name{};
        string getName();
        void print();
        int run();
};
