#include "CMenuItem.h"

namespace SNS
{
    CMenuItem::CMenuItem(std::string name, Func func) : item_name(name), func(func)
    {
    }

    std::string CMenuItem::getName()
    {
        return item_name;
    }

    void CMenuItem::print()
    {
        std::cout << item_name;
    }

    int CMenuItem::run()
    {
        return func();
    }
} // namespace SNS