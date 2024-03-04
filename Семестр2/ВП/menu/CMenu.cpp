#include "./CMenu.h"

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
            std::cout << i << ". ";
            items[i].print();
            std::cout << std::endl;
        }
    }

    int CMenu::runCommand()
    {
        print();
        std::cout << "\n   Select >> ";
        std::cin >> select;
        return items[select].run();
    }
} // namespace SNS