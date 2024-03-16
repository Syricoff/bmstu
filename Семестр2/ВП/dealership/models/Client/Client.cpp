#include "Client.h"

namespace SNS
{
    Client::Client(std::string name, std::string surname, int age, std::string login,
                   std::string password, std::string service)
        : User(name, surname, age, login, password), service(service)
    {
    }

    void Client::displayPublicInfo(){
        User::displayPublicInfo();
        std::cout << "Service: " << service << std::endl;
    }

    void Client::displayPrivateInfo(){
        User::displayPrivateInfo();
    }

    std::string Client::getService() const
    {
        return service;
    }

    void Client::setService(const std::string &service)
    {
        this->service = service;
    }
}
