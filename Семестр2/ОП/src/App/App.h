#pragma once

#include "../Menu/CMenu/CMenu.h"
#include "../Menu/CMenuItem/CMenuItem.h"
#include "../Models/DataBase.h"
#include "../Models/HotelRoom.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;

class App
{
private:
    DataBase &db = DataBase::getInstance("./db.csv");
    bool m_is_running{true};
    App(){};

public:
    App(const App &) = delete;
    App &operator=(const App &) = delete;

    static App &createApp();

    CMenu *createMainMenu();
    CMenu *createSearchMenu();

    // Методы для сортировки, поиска и вывода данных на экран
    void sortedData();
    void searchData();
    void displayData(List &tempData);
    void displayData();
    void addRecord();
    void deleteRecord();
    void editRecord();

    int start();
};
