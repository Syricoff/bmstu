#pragma once
#include "../User/User.h"

namespace SNS
{
    class Employee : public User
    {
    public:
        Employee(std::string name, std::string surname, int age, std::string login,
               std::string password, std::string post);
        std::string getPost() const;
        void setPost(const std::string &post);
        void displayPublicInfo();
        void displayPrivateInfo();

    protected:
        std::string post;
    };
}
