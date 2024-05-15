#include "DataBase.h"

void DataBase::loadRecords()
{
    std::fstream file(filePath, std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        while (!file.eof())
        {
            HotelRoom room(0, "", 0.0, "", "", 0, 0.0, ""); // Создаем временный объект для чтения данных
            file >> room;
            if (!file.eof()) // Проверяем не достигли ли конца файла
            {
                records.push_back(room);
            }
        }
        file.close();
    }
}

void DataBase::saveRecords()
{
    std::fstream file(filePath, std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (const auto &room : records)
    {
        file << room << "\n";
    }
    cout << "Good" << std::endl;
    file.close();
}

List DataBase::getRecords() const { return records; }

void DataBase::addRecord(const HotelRoom &room)
{
    records.push_back(room);
    // saveRecords();
}

void DataBase::deleteRecord(int id)
{
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if (it->getId() == id)
        {
            records.erase(it);
            break;
        }
    }
}

void DataBase::editRecord(int id, const HotelRoom &newRoom)
{
    for (auto &room : records)
    {
        if (room.getId() == id)
        {
            room = newRoom;
            break;
        }
    }
}

DataBase::~DataBase(){
    saveRecords();
    records.clear();
}