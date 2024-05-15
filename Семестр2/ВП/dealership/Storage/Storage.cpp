#include "Storage.h"

Storage *Storage::s_storage{};
Storage::Storage(string root_path){};

Storage &Storage::createStorage(string root_path)
{
    static Storage storage{root_path};

    s_storage = &storage;

    return storage;
}

Storage::~Storage()
{

    // удаляем корабли
    for (auto *pItem : users_list)
    {
        delete pItem;
    }

    for (auto *pItem : cars_list)
    {
        delete pItem;
    }
}

Storage *Storage::getStorage()
{

    // проверка ошибки
    if (s_storage == nullptr)
    {
        std::cerr << "Вызов getStore раньше чем createStore! Получен нулевой указатель!" << std::endl;
    }

    return s_storage;
}
