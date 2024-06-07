#include "Menu/CMenu/CMenu.h"
#include "Menu/CMenuItem/CMenuItem.h"
#include "Models/Car/Car.h"
#include "Models/Client/Client.h"
#include "Models/Employee/Employee.h"
#include "Storage/Storage.h"
#include "Tools/Tools.h"

#include <algorithm>
#include <exception>
#include <iostream>

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
    SNS::clearScreen();
    cout << "Добро пожаловать в главное меню\n"
         << "============================================\n\n"
         << endl;
}

namespace SNS
{
    void displayCarsFromStorage()
    {
        try
        {
            auto cars = Storage::getStorage()->cars_list;
            for (const auto &car : cars)
            {
                cout << *car << endl;
            }

            if (cars.empty())
            {
                std::cout << "Машин нет." << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка при отображении машин из хранилища: " << e.what() << std::endl;
        }
    }

    void displayClientsFromStorage()
    {
        try
        {
            auto clients = Storage::getStorage()->users_list;
            for (const auto &client : clients)
            {
                cout << *(Client *)client << endl;
            }

            if (clients.empty())
            {
                std::cout << "Клиентов нет." << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка при отображении клиентов из хранилища: " << e.what() << std::endl;
        }
    }

    void addCarToStorage()
    {
        try
        {
            Car car;
            std::cin >> car;
            Storage::getStorage()->cars_list.push_back(new Car(*static_cast<Car *>(&car)));
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка при добавлении машины в хранилище: " << e.what() << std::endl;
        }
    }

    void removeCarFromStorage()
    {
        displayCarsFromStorage();
        if (!Storage::getStorage()->cars_list.empty())
        {
            try
            {
                std::string brand;
                std::cout << "Введите марку машины для удаления: ";
                std::cin >> brand;

                auto &cars = Storage::getStorage()->cars_list;
                auto it = std::find_if(cars.begin(), cars.end(), [&](const Car *car)
                                       { return car->getBrand() == brand; });

                if (it != cars.end())
                {
                    cars.erase(it);
                    std::cout << "Машина успешно удалена из хранилища." << std::endl;
                }
                else
                {
                    std::cout << "Машина с указанной маркой не найдена в хранилище." << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Ошибка при удалении машины из хранилища: " << e.what() << std::endl;
            }
        }
    }

    void sortCarsInStorage()
    {
        try
        {
            auto &cars = Storage::getStorage()->cars_list;
            std::sort(cars.begin(), cars.end(), [&](const Car *a, const Car *b)
                      { return a > b; });
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка при сортировке машин в хранилище: " << e.what() << std::endl;
        }
    }

    void addClientToStorage()
    {
        try
        {
            Client client;
            std::cin >> client;
            Storage::getStorage()->users_list.push_back(new Client(*static_cast<Client *>(&client)));
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка при добавлении клиента в хранилище: " << e.what() << std::endl;
        }
    }

    void removeClientFromStorage()
    {
        displayClientsFromStorage();
        if (!Storage::getStorage()->users_list.empty())
        {
            try
            {
                std::string login;
                std::cout << "Введите логин клиента для удаления: ";
                std::cin >> login;

                auto &clients = Storage::getStorage()->users_list;
                auto it = std::find_if(clients.begin(), clients.end(), [&](const User *client)
                                       { return client->getLogin() == login; });

                if (it != clients.end())
                {
                    clients.erase(it);
                    std::cout << "Клиент успешно удален из хранилища." << std::endl;
                }
                else
                {
                    std::cout << "Клиент с указанным логином не найден в хранилище." << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Ошибка при удалении клиента из хранилища: " << e.what() << std::endl;
            }
        }
    }

    void sortClientsInStorage()
    {
        try
        {
            auto &clients = Storage::getStorage()->users_list;
            std::sort(clients.begin(), clients.end(), [&](const User *a, const User *b)
                      { return a < b; });
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка при сортировке клиентов в хранилище: " << e.what() << std::endl;
        }
    }

    CMenu *createMainMenu()
    {
        CMenu *menu = new CMenu("Главное меню",
                                ItemList{
                                    CMenuItem("Добавить машину в хранилище", [](int index) -> int
                                              {addCarToStorage(); return index; }),
                                    CMenuItem("Удалить машину из хранилища", [](int index) -> int
                                              {removeCarFromStorage(); return index; }),
                                    CMenuItem("Сортировать машины в хранилище", [](int index) -> int
                                              {sortCarsInStorage(); return index; }),
                                    CMenuItem("Добавить клиента в хранилище", [](int index) -> int
                                              {addClientToStorage(); return index; }),
                                    CMenuItem("Удалить клиента из хранилища", [](int index) -> int
                                              {removeClientFromStorage(); return index; }),
                                    CMenuItem("Сортировать клиентов в хранилище", [](int index) -> int
                                              {sortClientsInStorage(); return index; }),
                                    CMenuItem("Показать все машины в хранилище", [](int index) -> int
                                              {displayCarsFromStorage(); return index; }),
                                    CMenuItem("Показать всех клиентов в хранилище", [](int index) -> int
                                              {displayClientsFromStorage(); return index; }),
                                    CMenuItem("Выйти", [](int index) -> int
                                              {return -1; })});
        return menu;
    }
}

int main()
{
    using namespace SNS;

    renderMain();

    Storage::createStorage("./db.txt");
    Storage *storage = Storage::getStorage();

    CMenu &menu = *createMainMenu();

    do
    {
        cout << menu;

        try
        {
            cin >> menu;
            clearScreen();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка при взаимодействии с меню: " << e.what() << std::endl;
        }
    } while (menu() != -1);

    delete &menu;
    return 0;
}
