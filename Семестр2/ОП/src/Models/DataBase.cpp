#include "DataBase.h"

void DataBase::loadRecords()
{
    std::ifstream file(filePath);
    if (file.is_open())
    {
        string line;
        std::getline(file, line); // Skip the header row

        records.clear();

        while (getline(file, line))
        {
            stringstream ss(line);
            string field;
            vector<string> fields;

            while (getline(ss, field, ';'))
            {
                fields.push_back(field);
            }

            if (fields.size() == 8)
            {
                int id = stoi(fields[0]);
                string roomType = fields[1];
                double pricePerNight = stod(fields[2]);
                string checkInDate = fields[3];
                string checkOutDate = fields[4];
                unsigned int numGuests = stoi(fields[5]);
                double totalCost = stod(fields[6]);
                string notes = fields[7];

                HotelRoom room(id, roomType, pricePerNight, checkInDate, checkOutDate, numGuests, totalCost, notes);
                records.push_back(room);
            }
        }

        file.close();
    }
    else
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
}

void DataBase::saveRecords()
{
    std::ofstream file(filePath);
    if (file.is_open()) {
        
        file << "id;тип номера;цена за ночь;дата заезда;дата выезда;количество гостей;общая стоимость;примечания" << std::endl;

        for (const HotelRoom& room : records) {
            file << room << std::endl;
        }

        file.close();
    } else {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
}

List DataBase::getRecords() const { return records; }

void DataBase::addRecord(const HotelRoom &room)
{
    records.push_back(room);
    saveRecords();
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
    saveRecords();
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
    saveRecords();
}

DataBase::~DataBase()
{
    saveRecords();
    records.clear();
}