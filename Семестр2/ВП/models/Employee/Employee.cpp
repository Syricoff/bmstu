#include "Employee.h"

namespace SNS
{

    Employee::Employee(std::string name, std::string surname, int age, std::string login,
                       std::string password, std::string post)
        : User(name, surname, age, login, password), post(post)
    {
    }

    std::string Employee::getPost() const
    {
        return post;
    }

    void Employee::setPost(const std::string &post)
    {
        this->post = post;
    }

    void Employee::displayPublicInfo()
    {
        User::displayPublicInfo();
        std::cout << "Post: " << post << std::endl;
    }

    void Employee::displayPrivateInfo()
    {
        User::displayPrivateInfo();
    }
}