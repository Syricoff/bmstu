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

    void Employee::displayPublicInfo() const
    {
        User::displayPublicInfo();
        std::cout << "Post: " << post << std::endl;
    }

    void Employee::displayPrivateInfo() const
    {
        User::displayPrivateInfo();
    }

    bool Employee::operator<(const Employee &employee){
        return post < employee.post;
    }

    std::ostream &operator<<(std::ostream &out, const Employee &employee)
    {
        employee.displayPublicInfo();
        employee.displayPrivateInfo();
        return out;
    }

    std::istream &operator>>(std::istream &in, Employee &employee) {
        std::cout << "Enter post: ";
        std::getline(in, employee.post);
        return in;
    }
}