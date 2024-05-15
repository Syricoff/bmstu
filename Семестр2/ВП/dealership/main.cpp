#include "Menu/CMenu/CMenu.h"
#include "Menu/CMenuItem/CMenuItem.h"
#include "Models/Car/Car.h"
#include "Models/Client/Client.h"
#include "Models/Employee/Employee.h"
#include "Storage/Storage.h"
#include "Tools/Tools.h"
#include <algorithm>
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

    void addCarToStorage()
    {
        Car car;
        std::cin >> car;
        Storage::getStorage()->cars_list.push_back(new Car(*static_cast<Car *>(&car)));
    }

    void removeCarFromStorage()
    {
        std::string brand;
        std::cout << "Введите марку машины для удаления: ";
        std::cin >> brand;

        auto &cars = Storage::getStorage()->cars_list;
        auto it = std::find_if(cars.begin(), cars.end(), [&](const Car &car)
                               { return car.getBrand() == brand; });

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

    void sortCarsInStorage()
    {
        std::string criteria;
        std::cout << "Выберите критерий сортировки для машин (brand, price, year): ";
        std::cin >> criteria;

        auto &cars = Storage::getStorage()->cars_list;
        std::sort(cars.begin(), cars.end(), [](const Car &a, const Car &b)
                  { return a > b; });
    }

    void addEmployeeToStorage()
    {
        Employee employee;
        std::cin >> employee;
        Storage::getStorage()->users_list.push_back(new Employee(*static_cast<Employee *>(&employee)));
    }

    void removeEmployeeFromStorage()
    {
        std::string login;
        std::cout << "Введите логин сотрудника для удаления: ";
        std::cin >> login;

        auto &employees = Storage::getStorage()->users_list;
        auto it = std::find_if(employees.begin(), employees.end(), [&](const Employee &employee)
                               { return employee.getLogin() == login; });

        if (it != employees.end())
        {
            employees.erase(it);
            std::cout << "Сотрудник успешно удален из хранилища." << std::endl;
        }
        else
        {
            std::cout << "Сотрудник с указанным логином не найден в хранилище." << std::endl;
        }
    }

    void sortEmployeesInStorage()
    {
        std::string criteria;
        std::cout << "Выберите критерий сортировки для сотрудников (name, surname, age, login, post): ";
        std::cin >> criteria;

        auto &employees = Storage::getStorage()->users_list;
        std::sort(employees.begin(), employees.end(), [&](const Employee &a, const Employee &b)
                  {
        if (criteria == "name") {
            return a.getName() < b.getName();
        } else if (criteria == "surname") {
            return a.getSurname() < b.getSurname();
        } else if (criteria == "age") {
            return a.getAge() < b.getAge();
        } else if (criteria == "login") {
            return a.getLogin() < b.getLogin();
        } else if (criteria == "post") {
            return a.getPost() < b.getPost();
        } else {
            return false;
        } });
    }

    void addClientToStorage()
    {
        Client client;
        std::cin >> client;
        Storage::getStorage()->users_list.push_back(new Client(*static_cast<Client *>(&client)));
    }

    void removeClientFromStorage()
    {
        std::string login;
        std::cout << "Введите логин клиента для удаления: ";
        std::cin >> login;

        auto &clients = Storage::getStorage()->users_list;
        auto it = std::find_if(clients.begin(), clients.end(), [&](const Client &client)
                               { return client.getLogin() == login; });

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

    void sortClientsInStorage()
    {
        std::string criteria;
        std::cout << "Выберите критерий сортировки для клиентов (name, surname, age, login, service): ";
        std::cin >> criteria;

        auto &clients = Storage::getStorage()->users_list;
        std::sort(clients.begin(), clients.end(), [&](const Client &a, const Client &b)
                  {
        if (criteria == "name") {
            return a.getName() < b.getName();
        } else if (criteria == "surname") {
            return a.getSurname() < b.getSurname();
        } else if (criteria == "age") {
            return a.getAge() < b.getAge();
        } else if (criteria == "login") {
            return a.getLogin() < b.getLogin();
        } else if (criteria == "service") {
            return a.getService() < b.getService();
        } else {
            return false;
        } });
    }

    void displayCarsFromStorage()
    {
        auto &cars = Storage::getStorage()->cars_list;
        for (const auto &car : cars)
        {
            cout << car;
        }

        if (cars.empty())
        {
            std::cout << "Машин нет." << std::endl;
        }
    }

    void displayEmployeesFromStorage()
    {
        auto &employees = Storage::getStorage()->users_list;
        for (const auto &employee : employees)
        {
            cout << employee;
        }

        if (employees.empty())
        {
            std::cout << "Сотрудников нет." << std::endl;
        }
    }

    void displayClientsFromStorage()
    {
        auto &clients = Storage::getStorage()->users_list;
        for (const auto &client : clients)
        {
            cout << client;
        }

        if (clients.empty())
        {
            std::cout << "Клиентов нет." << std::endl;
        }
    }

    CMenu *createMainMenu()
    {
        CMenu *menu = new CMenu("Главное меню",
                                ItemList{
                                    CMenuItem("Добавить машину в хранилище", [](int index) -> int
                                              {addCarToStorage; return index; }),
                                    CMenuItem("Удалить машину из хранилища", [](int index) -> int
                                              {removeCarFromStorage; return index; }),
                                    CMenuItem("Сортировать машины в хранилище", [](int index) -> int
                                              {sortCarsInStorage; return index; }),
                                    CMenuItem("Добавить сотрудника в хранилище", [](int index) -> int
                                              {addEmployeeToStorage; return index; }),
                                    CMenuItem("Удалить сотрудника из хранилища", [](int index) -> int
                                              {removeEmployeeFromStorage; return index; }),
                                    CMenuItem("Сортировать сотрудников в хранилище", [](int index) -> int
                                              {sortEmployeesInStorage; return index; }),
                                    CMenuItem("Добавить клиента в хранилище", [](int index) -> int
                                              {addClientToStorage; return index; }),
                                    CMenuItem("Удалить клиента из хранилища", [](int index) -> int
                                              {removeClientFromStorage; return index; }),
                                    CMenuItem("Сортировать клиентов в хранилище", [](int index) -> int
                                              {sortClientsInStorage; return index; }),
                                    CMenuItem("Показать все машины в хранилище", [](int index) -> int
                                              {displayCarsFromStorage; return index; }),
                                    CMenuItem("Показать всех сотрудников в хранилище", [](int index) -> int
                                              {displayEmployeesFromStorage; return index; }),
                                    CMenuItem("Показать всех клиентов в хранилище", [](int index) -> int
                                              {displayClientsFromStorage; return index; })});
        return menu;
    }
}

int main()
{
    using namespace SNS;

    renderMain();
    Storage *storage = Storage::getStorage();

    CMenu &menu = *createMainMenu();

    // выводим меню
    cout << menu;

    // ожидаем ввод от пользователя
    cin >> menu;
    clearScreen();
    // запускаем заданную функцию
    menu();

    // удаляем меню
    delete &menu;
    return 0;
}

// g++ main.cpp ./models/CMenu/CMenu.cpp ./models/CMenuItem/CMenuItem.cpp ./models/Car/Car.cpp ./models/User/User.cpp ./models/Client/Client.cpp ./models/Employee/Employee.cpp && ./a.out