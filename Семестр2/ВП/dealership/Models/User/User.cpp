#include "User.h"

namespace SNS
{
    User::User(std::string name, std::string surname, int age, std::string login, std::string password) : m_name(name), m_surname(surname), m_age(age), m_login(login), m_password(password)
    {
    }
    void User::displayPublicInfo() const
    {
        std::cout << "Name: " << m_name << std::endl;
        std::cout << "Surname: " << m_surname << std::endl;
        std::cout << "Age: " << m_age << std::endl;
    }
    void User::displayPrivateInfo() const
    {
        std::cout << "Login: " << m_login << std::endl;
        std::cout << "Password: " << m_password << std::endl;
    }
}