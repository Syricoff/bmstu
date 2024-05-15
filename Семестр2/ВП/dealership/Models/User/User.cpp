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

    std::string User::getName() const
    {
        return m_name;
    }

    std::string User::getSurname() const
    {
        return m_surname;
    }

    int User::getAge() const
    {
        return m_age;
    }

    std::string User::getLogin() const
    {
        return m_login;
    }

    std::string User::getPassword() const
    {
        return m_password;
    }

    void User::setName(const std::string &name)
    {
        m_name = name;
    }

    void User::setSurname(const std::string &surname)
    {
        m_surname = surname;
    }

    void User::setAge(int age)
    {
        m_age = age;
    }

    void User::setLogin(const std::string &login)
    {
        m_login = login;
    }

    void User::setPassword(const std::string &password)
    {
        m_password = password;
    }

    
}