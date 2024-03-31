#include "Menu/CMenu/CMenu.h"
#include "Menu/CMenuItem/CMenuItem.h"
#include "Models/Car/Car.h"
#include "Models/Client/Client.h"
#include "Models/Employee/Employee.h"

using namespace std;

#pragma region функции-заглушки

int testCar(int index)
{
    using namespace SNS;
    Car car("Toyota", 25000.0, 2022, "Sedan", "Bluetooth, Backup Camera");
    car.displayInfo();
    return index;
}

int testEmployee(int index)
{
    using namespace SNS;
    Employee employee("John", "Doe", 25, "johndoe", "12345", "Manager");
    employee.displayPublicInfo();
    employee.displayPrivateInfo();
    return index;
}

int testClient(int index)
{
    using namespace SNS;
    Client client("John", "Doe", 25, "johndoe", "12345", "Service");
    client.displayPublicInfo();
    client.displayPrivateInfo();
    return index;
}
#pragma endregion

void renderMain()
{
    system("clear");
    cout << "Добро пожаловать в главное меню\n"
         << "============================================\n\n"
         << endl;
}
namespace SNS
{
    CMenu *createMainMenu()
    {
        CMenu *menu = new CMenu("Главное меню",
                                ItemList{
                                    CMenuItem("Тест машины", testCar),
                                    CMenuItem("Тест сотрудника", testEmployee),
                                    CMenuItem("Тест клиента", testClient)});
        return menu;
    }
}
int main()
{
    using namespace SNS;

    renderMain();
    CMenu &menu = *createMainMenu();

    // выводим меню
    cout << menu;

    // ожидаем ввод от пользователя
    cin >> menu;

    // запускаем заданную функцию
    menu();

    // удаляем меню
    delete &menu;
    return 0;
}

// g++ main.cpp ./models/CMenu/CMenu.cpp ./models/CMenuItem/CMenuItem.cpp ./models/Car/Car.cpp ./models/User/User.cpp ./models/Client/Client.cpp ./models/Employee/Employee.cpp && ./a.out