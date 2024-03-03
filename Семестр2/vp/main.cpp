#include "menu/CMenu.h"
#include "menu/CMenuItem.h"

using namespace std;

#pragma region функции-заглушки
int f1()
{
    std::cout << "function f1 is running...\n\n";
    return 1;
}

int f2()
{
    std::cout << "function f2 is running...\n\n";
    return 2;
}

int f3()
{
    std::cout << "function f3 is running...\n\n";
    return 3;
}

int exit()
{
    std::cout << "Exit is running...\n\n";
    exit(0);
    return -1;
}

int smileFace()
{
    std::cout << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "*  o o  *" << std::endl;
    std::cout << "*   v   *" << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "  *****  " << std::endl;
    std::cout << std::endl;

    return 1;
}

int squareOf()
{
    std::cout << "Square: " << 5 * 5 << std::endl;
    return 1;
}
#pragma endregion

const int ITEMS_NUMBER = 6;

int main()
{
    CMenuItem items[ITEMS_NUMBER]{CMenuItem{"first item", f1},   CMenuItem{"second item", f2},
                                  CMenuItem{"third item", f3},   CMenuItem{"Smile Face", smileFace},
                                  CMenuItem("Square", squareOf), CMenuItem{"Exit", exit}};
    CMenu menu("My console menu", items, ITEMS_NUMBER);
    while (menu.runCommand())
    {
    };

    return 0;
}

// g++ main.cpp ./menu/CMenu.cpp ./menu/CMenuItem.cpp && ./a.out