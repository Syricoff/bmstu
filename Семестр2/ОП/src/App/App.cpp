#include "App.h"

App &App::createApp()
{
    static App app{};
    return app;
}
// Методы для сортировки, поиска и вывода данных на экран
void App::sortedData()
{
    List temData = db.getRecords();
    std::sort(temData.begin(), temData.end(), [](const HotelRoom &a, const HotelRoom &b)
              { return a.getRoomType() < b.getRoomType(); });
}

void App::searchData()
{
    cout << endl;
}

void App::displayData()
{
    List tempData = db.getRecords();
    if (tempData.empty())
    {
        std::cout << "No records found." << std::endl;
    }
    else
    {
        for (const HotelRoom &record : tempData)
        {
            cout << record << endl;
        }
    }
}

// Методы для добавления, удаления и редактирования данных
void App::addRecord()
{
    int id, numGuests;
    std::string roomType, checkInDate, checkOutDate, notes;
    double pricePerNight, totalCost;

    // Запрос информации у пользователя
    std::cout << "Enter Room ID: ";
    std::cin >> id;
    std::cout << "Enter Room Type: ";
    std::cin >> roomType;
    std::cout << "Enter Price Per Night: ";
    std::cin >> pricePerNight;
    std::cout << "Enter Check-in Date: ";
    std::cin >> checkInDate;
    std::cout << "Enter Check-out Date: ";
    std::cin >> checkOutDate;
    std::cout << "Enter Number of Guests: ";
    std::cin >> numGuests;
    std::cout << "Enter Total Cost: ";
    std::cin >> totalCost;
    std::cout << "Enter Notes: ";
    std::cin.ignore(); // Очистка буфера ввода
    std::getline(std::cin, notes);

    // Создание новой записи
    HotelRoom newRecord(id, roomType, pricePerNight, checkInDate, checkOutDate, numGuests, totalCost, notes);

    // Добавление записи в базу данных
    db.addRecord(newRecord);
}

void App::deleteRecord()
{
    db.saveRecords();
}

void App::editRecord()
{
    db.loadRecords();
}

CMenu *App::createMainMenu()
{
    CMenu *menu = new CMenu("Главное меню",
                            ItemList{
                                CMenuItem("Добавить бронь", [this](int index) -> int
                                          {this->addRecord(); return index; }),
                                CMenuItem("Удалить бронь", [this](int index) -> int
                                          {this->deleteRecord(); return index; }),
                                CMenuItem("Редактировать бронь", [this](int index) -> int
                                          {this->editRecord(); return index; }),
                                CMenuItem("Вывести список", [this](int index) -> int
                                          {this->displayData(); return index; }),
                                CMenuItem("Сортированный список", [this](int index) -> int
                                          {this->sortedData(); return index; }),
                                CMenuItem("Поиск", [this](int index) -> int
                                          {this->searchData(); return index; }),
                                CMenuItem("Выход", [this](int index) -> int
                                          {this->m_is_running = false; return index; })});
    return menu;
}

int App::start()
{
    CMenu &menu = *createMainMenu();
    db.loadRecords();

    while (m_is_running)
    {
        cout << menu;
        cin >> menu;
        menu();
    }

    delete &menu;

    return 0;
}
