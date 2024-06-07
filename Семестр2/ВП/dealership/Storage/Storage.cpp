#include "Storage.h"
#include "../Exception/Exception.h"

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
    try {
        if (s_storage == nullptr) throw SNS::StorageException("\nВызов getStore раньше чем createStore! Получен нулевой указатель!\n");
    }
    catch (SNS::StorageException & invalid_store) {
        std::cerr << invalid_store.what();
    }

    return s_storage;
}
