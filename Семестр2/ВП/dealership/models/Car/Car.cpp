#include "Car.h"
#include <iostream>

namespace SNS
{
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

}

