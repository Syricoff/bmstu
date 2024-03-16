#include "CMenu.h"

namespace SNS
{
    CMenu::CMenu(std::string title, CMenuItem *items, size_t count) : title(title), items(items), count(count)
    {
    }

    int CMenu::getSelect() const
    {
        return select;
    }

    bool CMenu::isRun() const
    {
        return running;
    }

    size_t CMenu::getCount() const
    {
        return count;
    }

    std::string CMenu::getTitle()
    {
        return title;
    }

    CMenuItem *CMenu::getItems()
    {
        return items;
    }

    void CMenu::print()
    {
        std::cout << title << std::endl;
        for (size_t i{}; i < count; ++i)
        {
            std::cout << i + 1 << ". ";
            items[i].print();
            std::cout << std::endl;
        }
        std::cout << "0. Выход" << std::endl;
    }

    int CMenu::runCommand()
    {
        print();
        std::cout << "\n Select >> ";
        std::cin >> select;
        if (select == 0)
        {
            running = false;
            return -1;
        };
        return items[select - 1].run();
    }
} // namespace SNS