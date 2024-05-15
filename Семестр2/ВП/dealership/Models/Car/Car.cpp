#include "Car.h"

namespace SNS
{
    Car::Car(){};
    Car::Car(const std::string brand, double price, int year, const std::string description, const std::string features)
        : brand(brand), price(price), year(year), description(description), features(features)
    {
    }

    void Car::displayInfo()
    {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Features: " << features << std::endl;
    }

    std::string Car::getBrand() const
    {
        return brand;
    }

    double Car::getPrice() const
    {
        return price;
    }

    int Car::getYear() const
    {
        return year;
    }

    std::string Car::getDescription() const
    {
        return description;
    }

    std::string Car::getFeatures() const
    {
        return features;
    }

    void Car::setBrand(const std::string &brand)
    {
        this->brand = brand;
    }

    void Car::setPrice(double price)
    {
        this->price = price;
    }

    void Car::setYear(int year)
    {
        this->year = year;
    }

    void Car::setDescription(const std::string &description)
    {
        this->description = description;
    }

    void Car::setFeatures(const std::string &features)
    {
        this->features = features;
    }

    bool Car::operator<(const Car &other) const{
        return year < other.year;
    }

    bool Car::operator>(const Car &other) const{
        return year > other.year;
    }

    std::ostream &operator<<(std::ostream &out, const Car &car)
    {
        out << "Brand: " << car.brand << std::endl;
        out << "Price: " << car.price << std::endl;
        out << "Year: " << car.year << std::endl;
        out << "Description: " << car.description << std::endl;
        out << "Features: " << car.features << std::endl;
        return out;
    }

    std::istream &operator>>(std::istream &in, Car &car)
    {
        cout << "Enter brand: ";
        in >> car.brand;
        cout << "Enter price: ";
        in >> car.price;
        cout << "Enter year: ";
        in >> car.year;
        cout << "Enter description: ";
        in >> car.description;
        cout << "Enter features: ";
        in >> car.features;
        return in;
    }
    

}

