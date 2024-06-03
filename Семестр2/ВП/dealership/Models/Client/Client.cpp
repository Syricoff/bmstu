#include "Client.h"

namespace SNS
{
    Client::Client() : User()
    {
    }
    Client::~Client() {}
    Client::Client(std::string name, std::string surname, int age, std::string login,
                   std::string password, std::string service)
        : User(name, surname, age, login, password), service(service)
    {
    }

    void Client::displayPublicInfo() const
    {
        User::displayPublicInfo();
        std::cout << "Service: " << service << std::endl;
    }

    void Client::displayPrivateInfo() const
    {
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

    bool Client::operator<(const Client &other) const
    {
        return service < other.service;
    }

    bool Client::operator>(const Client &other) const
    {
        return service > other.service;
    }

    std::ostream &operator<<(std::ostream &out, const Client &client)
    {
        out << "Name: " << client.getName() << std::endl;
        out << "Surname: " << client.getSurname() << std::endl;
        out << "Age: " << client.getAge() << std::endl;
        out << "Login: " << client.getLogin() << std::endl;
        out << "Password: " << client.getPassword() << std::endl;
        out << "Service: " << client.service << std::endl;
        return out;
    }

    std::istream &operator>>(std::istream &in, Client &client)
    {
        std::string name, surname, login, password, service;
        int age;

        cout << "Enter name: ";
        in >> name;
        cout << "Enter surname: ";
        in >> surname;
        cout << "Enter age: ";
        in >> age;
        cout << "Enter login: ";
        in >> login;
        cout << "Enter password: ";
        in >> password;
        cout << "Enter service: ";
        in >> service;

        client.setName(name);
        client.setSurname(surname);
        client.setAge(age);
        client.setLogin(login);
        client.setPassword(password);
        client.setService(service);

        return in;
    }
}
