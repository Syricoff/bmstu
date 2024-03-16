#include "models/CMenu/CMenu.h"
#include "models/CMenuItem/CMenuItem.h"
#include "models/Car/Car.h"
#include "models/Client/Client.h"
#include "models/Employee/Employee.h"

using namespace std;

#pragma region функции-заглушки

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

int testCar()
{
    using namespace SNS;
    Car car("Toyota", 25000.0, 2022, "Sedan", "Bluetooth, Backup Camera");
    car.displayInfo();
    return 1;
}

int testEmployee(){
    using namespace SNS;
    Employee employee("John", "Doe", 25, "johndoe", "12345", "Manager");
    employee.displayPublicInfo();
    employee.displayPrivateInfo();
    return 1;
}

int testClient(){
    using namespace SNS;
    Client client("John", "Doe", 25, "johndoe", "12345", "Service");
    client.displayPublicInfo();
    client.displayPrivateInfo();
    return 1;
}
#pragma endregion

const int ITEMS_NUMBER = 6;

int main()
{
    using namespace SNS;

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"Смайлик)", smileFace},
        CMenuItem("Квадрат 5", squareOf5),
        CMenuItem("Привет мир", hello),
        CMenuItem("Тест машины", testCar),
        CMenuItem("Тест сотрудника", testEmployee),
        CMenuItem("Тест клиента", testClient)};

    CMenu menu("Главное меню", items, ITEMS_NUMBER);
    while (menu.isRun())
    {
        menu.runCommand();
    };

    return 0;
}

// g++ main.cpp ./models/CMenu/CMenu.cpp ./models/CMenuItem/CMenuItem.cpp ./models/Car/Car.cpp ./models/User/User.cpp ./models/Client/Client.cpp ./models/Employee/Employee.cpp && ./a.out