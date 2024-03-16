#pragma once
#include "../User/User.h"

namespace SNS
{
    class Client : public User
    {
    public:
        Client(std::string, std::string, int, std::string,
               std::string, std::string);
        std::string getService() const;
        void setService(const std::string &service);
        void displayPublicInfo();
        void displayPrivateInfo();

    protected:
        std::string service;
    };
}
