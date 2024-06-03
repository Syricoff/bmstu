#include "Employee.h"

namespace SNS
{
    Employee::Employee() : User()
    {
    }
    Employee::Employee(std::string name, std::string surname, int age, std::string login,
                       std::string password, std::string post)
        : User(name, surname, age, login, password), post(post)
    {
    }
    Employee::~Employee(){}

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
    bool Employee::operator>(const Employee &employee){
        return post > employee.post;
    }

    std::ostream &operator<<(std::ostream &out, const Employee &employee)
    {
        out << "Name: " << employee.getName() << std::endl;
        out << "Surname: " << employee.getSurname() << std::endl;
        out << "Age: " << employee.getAge() << std::endl;
        out << "Login: " << employee.getLogin() << std::endl;
        out << "Password: " << employee.getPassword() << std::endl;
        out << "Post: " << employee.post << std::endl;
        return out;
    }

    std::istream &operator>>(std::istream &in, Employee &employee)
    {
        std::string name, surname, login, password, post;
        int age;

        cout << "Enter name: ";
        in >> name;
        cout << "Enter surname: ";
        in >> surname;
        cout << "Enter age: ";
        in >> age;
        cout << "Enter login: ";
        in >> login;
        cout << "Enter password: ";
        in >> password;
        cout << "Enter post: ";
        in >> post;

        employee.setName(name);
        employee.setSurname(surname);
        employee.setAge(age);
        employee.setLogin(login);
        employee.setPassword(password);
        employee.setPost(post);

        return in;
    }

}