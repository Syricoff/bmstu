#pragma once

#include <iostream>
#include <vector>
#include <./MyVector/MyVector.h>
namespace SNS
{
    class User
    {
    public:
        using UserList = std::vector<User *>;

        User() = default;

        User(std::string m_name, std::string, int, std::string, std::string);
        std::string m_name;
        std::string m_surname;
        int m_age;
        std::string m_login;
        std::string m_password;

        virtual void displayPublicInfo() const = 0;
        virtual void displayPrivateInfo() const = 0;

        std::string getName() const;
        std::string getSurname() const;
        int getAge() const;
        std::string getLogin() const;
        std::string getPassword() const;

        void setName(const std::string &name);
        void setSurname(const std::string &surname);
        void setAge(int age);
        void setLogin(const std::string &login);
        void setPassword(const std::string &password);
    };
}
