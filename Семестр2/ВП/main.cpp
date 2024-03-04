#include "menu/CMenu.h"
#include "menu/CMenuItem.h"

using namespace std;

#pragma region функции-заглушки

int exit()
{
    std::cout << "Exit is running...\n\n";
    exit(0);
    return -1;
}

int hello()
{
    std::cout << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cout << std::endl;

    return 3;
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

int squareOf5()
{
    std::cout << std::endl;
    std::cout << "Square: " << 5 * 5 << std::endl;
    std::cout << std::endl;

    return 2;
}
#pragma endregion

const int ITEMS_NUMBER = 4;

int main()
{
    using namespace SNS;

    CMenuItem items[ITEMS_NUMBER]{CMenuItem{"Выход", exit},
                                  CMenuItem{"Смайлик)", smileFace},
                                  CMenuItem("Квадрат 5", squareOf5),
                                  CMenuItem("Привет мир", hello)};

    CMenu menu("Главное меню", items, ITEMS_NUMBER);
    while (menu.runCommand())
    {
    };

    return 0;
}

// g++ main.cpp ./menu/CMenu.cpp ./menu/CMenuItem.cpp && ./a.out