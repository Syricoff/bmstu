#include "Car.h"
#include <exception>

namespace SNS
{
    Car::Car()
    {
    }

    Car::Car(const std::string brand, double price, int year, const std::string description, const std::string features)
        : brand(brand), price(price), year(year), description(description), features(features)
    {
        if (brand.empty() || description.empty() || features.empty() || price <= 0 || year <= 0)
        {
            throw CarException("Некорректные данные автомобиля");
        }
    }

    void Car::displayInfo() const
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
        if (brand.empty())
        {
            throw CarException("Недопустимое значение марки автомобиля");
        }
        this->brand = brand;
    }

    void Car::setPrice(double price)
    {
        if (price <= 0)
        {
            throw CarException("Недопустимое значение цены автомобиля");
        }
        this->price = price;
    }

    void Car::setYear(int year)
    {
        if (year <= 0)
        {
            throw CarException("Недопустимое значение года автомобиля");
        }
        this->year = year;
    }

    void Car::setDescription(const std::string &description)
    {
        if (description.empty())
        {
            throw CarException("Недопустимое значение описания автомобиля");
        }
        this->description = description;
    }

    void Car::setFeatures(const std::string &features)
    {
        if (features.empty())
        {
            throw CarException("Недопустимое значение характеристик автомобиля");
        }
        this->features = features;
    }

    bool Car::operator<(const Car &other) const
    {
        return year < other.year;
    }

    bool Car::operator>(const Car &other) const
    {
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
        std::string brand, description, features;
        double price;
        int year;

        cout << "Enter brand: ";
        in >> brand;
        cout << "Enter price: ";
        in >> price;
        cout << "Enter year: ";
        in >> year;
        cout << "Enter description: ";
        in >> description;
        cout << "Enter features: ";
        in >> features;

        if (brand.empty() || description.empty() || features.empty() || price <= 0 || year <= 0)
        {
            throw CarException("Некорректные данные автомобиля");
        }

        car.setBrand(brand);
        car.setPrice(price);
        car.setYear(year);
        car.setDescription(description);
        car.setFeatures(features);

        return in;
    }
}
