#pragma once

#include <iostream>
namespace SNS
{
    class User
    {
    public:
        User(std::string m_name, std::string, int, std::string, std::string);
        std::string m_name;
        std::string m_surname;
        int m_age;
        std::string m_login;
        std::string m_password;

        virtual void displayPublicInfo() = 0;
        virtual void displayPrivateInfo() = 0;
    };
}
