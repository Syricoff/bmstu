#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../Tools/Tools.h"
#include "../CMenuItem/CMenuItem.h"

using std::string;

namespace SNS
{

    using ItemList = std::vector<CMenuItem>;

    class CMenu
    {
    public:
        CMenu() = delete;
        CMenu &operator=(const CMenu &) = delete;
        CMenu(string, ItemList);

        void print(std::ostream &out = std::cout) const;

        void selectItem(int selected);
        int getSelected() const;

        int runSelected() const;
        int operator()() const;

        friend std::ostream &operator<<(std::ostream &out, const CMenu &menu);
        friend std::istream &operator>>(std::istream &in, CMenu &menu);

    private:
        int m_selected{-1};
        string m_title{};
        ItemList m_items{};
    };

ValidateNum getValidate(int);

} // namespace SNS