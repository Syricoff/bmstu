#pragma onse

#include "HotelRoom.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

using List = std::vector<HotelRoom>;

class DataBase
{
private:
    std::string filePath;
    List records;

public:
    static DataBase& getInstance(const std::string &filePath)
    {
        static DataBase instance(filePath);
        return instance;
    }

    DataBase(const DataBase&) = delete;
    DataBase& operator=(const DataBase&) = delete;

    List getRecords() const;

    void loadRecords();

    void saveRecords();

    void addRecord(const HotelRoom &room);

    void editRecord(int id, const HotelRoom &newRoom);

    void deleteRecord(int id);

private:
    ~DataBase();
    DataBase(const std::string &filePath) : filePath(filePath) {}
};

