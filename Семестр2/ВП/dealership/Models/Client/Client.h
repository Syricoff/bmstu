#pragma once
#include "../User/User.h"
#include <iostream>
#include "./Exception/Exception.h"

using std::cout;
using std::endl;

namespace SNS
{
    class Client : public User
    {
    public:
        Client();
        ~Client();
        Client(std::string, std::string, int, std::string,
               std::string, std::string);
        std::string getService() const;
        void setService(const std::string &service);
        void displayPublicInfo() const;
        void displayPrivateInfo() const;
        bool operator<(const Client &client) const;
        bool operator>(const Client &client) const;

        friend std::ostream &operator<<(std::ostream &out, const Client &client);
        friend std::istream &operator>>(std::istream &in, Client &client);

    protected:
        std::string service;
    };
}
