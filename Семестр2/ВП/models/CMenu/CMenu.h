#pragma once

#include "../CMenuItem/CMenuItem.h"
#include <cstddef>

namespace SNS
{
    class CMenu
    {
    public:
        CMenu(std::string, CMenuItem *, std::size_t);
        int getSelect() const;
        bool isRun() const;
        std::string getTitle();
        size_t getCount() const;
        CMenuItem *getItems();
        void print();
        int runCommand();

    private:
        int select{-1};
        size_t count{};
        bool running{true};
        std::string title{};
        CMenuItem *items{};
    };
} // namespace SNS