#pragma once

#include <string>
#include <vector>

#include "../Models/Car/Car.h"
#include "../Models/User/User.h"

using std::string;
using std::vector;

class Storage
{
public:
    Storage() = delete;
    Storage(const Storage &) = delete;            // удаляем конструктор копирования
    Storage &operator=(const Storage &) = delete; // удаляем оператор присваивания

    static Storage &createStorage(string root_path);
    static Storage *getStorage();

    ~Storage();

    string app_name{"Dealship"};
    SNS::Car::CarsList cars_list{};
    SNS::User::UserList users_list{};

private:
    explicit Storage(string root_path);

    static Storage *s_storage;
    
};
