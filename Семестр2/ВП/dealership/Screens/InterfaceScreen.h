#include <iostream>
#include <string>


using std::cout;
using std::string;
using std::endl;


class InterfaceScreen {
public:
    // метод запуска экрана - входная точка
    virtual int start() = 0;

    // метод выполняющий главную отрисовку экрана
    virtual void renderMain() const = 0;
};