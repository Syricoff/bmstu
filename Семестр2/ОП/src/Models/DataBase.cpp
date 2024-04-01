#include "DataBase.h"

void DataBase::loadRecords()
{
    std::fstream file(filePath, std::ios::in | std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    records.clear();

    HotelRoom tempRoom(0, "", 0.0, "", "", 0, 0.0, "");
    while (file.read(reinterpret_cast<char*>(&tempRoom), sizeof(tempRoom)))
    {
        records.push_back(tempRoom);
        HotelRoom tempRoom(0, "", 0.0, "", "", 0, 0.0, "");
    }

    file.close();
}

void DataBase::saveRecords()
{
    std::fstream file(filePath, std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (auto &room : records)
    {
        file.write(reinterpret_cast<const char*>(&room), sizeof(room));
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