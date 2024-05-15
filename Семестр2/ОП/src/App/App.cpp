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
    displayData(temData);
}


List searchRooms(const vector<HotelRoom> &rooms, const string &searchTerm)
{
    vector<std::pair<HotelRoom, int>> results;

    std::string lowerSearchTerm = searchTerm;
    std::transform(lowerSearchTerm.begin(), lowerSearchTerm.end(), lowerSearchTerm.begin(), ::tolower);

    for (const HotelRoom &room : rooms)
    {
        int matchCount = 0;

        if (room.getCheckInDate().find(lowerSearchTerm) != std::string::npos) {
            matchCount++;
        }

        if (room.getCheckOutDate().find(lowerSearchTerm) != std::string::npos) {
            matchCount++;
        }

        if (room.getNotes().find(lowerSearchTerm) != std::string::npos) {
            matchCount++;
        }

        if (room.getRoomType().find(lowerSearchTerm) != std::string::npos) {
            matchCount++;
        }

        if (matchCount > 0) {
            results.push_back(std::make_pair(room, matchCount));
        }
    }

    // Сортировка результатов по наибольшему совпадению
    std::sort(results.begin(), results.end(), [](const std::pair<HotelRoom, int> &a, const std::pair<HotelRoom, int> &b) {
        return a.second > b.second;
    });

    List finalResults;
    for (const std::pair<HotelRoom, int> &result : results) {
        finalResults.push_back(result.first);
    }


    return finalResults;
}

void App::searchData()
{
    string searchTerm;
    cout << "Введите поисковый запрос: ";
    cin.ignore();
    getline(cin, searchTerm);

    List rooms = db.getRecords();
    List results = searchRooms(rooms, searchTerm);

    if (results.empty()) {
        cout << "Ничего не найдено." << endl;
    } else {
        displayData(results);
    }
}



void App::displayData(List &tempData)
{
    if (tempData.empty())
    {
        std::cout << "Нет записей" << std::endl;
    }
    else
    {
        for (const HotelRoom &record : tempData)
        {
            cout << record << endl;
        }
    }
}

void App::displayData()
{
    List tempData = db.getRecords();
    displayData(tempData);
}

// Методы для добавления, удаления и редактирования данных
void App::addRecord()
{
    HotelRoom newRecord;
    cin >> newRecord;
    // Добавление записи в базу данных
    db.addRecord(newRecord);
}

void App::deleteRecord()
{
    displayData();
    std::cout << "Введите id для удаления" << std::endl;
    int id{};
    std::cin >> id;
    db.deleteRecord(id);
}

void App::editRecord()
{
    displayData();
    std::cout << "Введите id для изменения" << std::endl;
    int id{};
    std::cin >> id;

    HotelRoom newRoom;
    std::cin >> newRoom;

    db.editRecord(id, newRoom);
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

    while (m_is_running)
    {
        db.loadRecords();
        cout << menu;
        cin >> menu;
        menu();
    }

    delete &menu;

    return 0;
}
