#pragma once
#include "../User/User.h"

#include <iostream>
#include <string>

using std::string;

namespace SNS
{
    class Employee : public User
    {
    public:
        Employee(string name, string surname, int age, string login,
                 string password, string post);
        string getPost() const;
        void setPost(const string &post);
        void displayPublicInfo() const;
        void displayPrivateInfo() const;
        friend std::ostream &operator<<(std::ostream &out, const Employee &employee);
        friend std::istream &operator>>(std::istream &in, Employee &employee);
        bool operator<(const Employee &employee);
        bool operator>(const Employee &employee);

    protected:
        std::string post;
    };
}
