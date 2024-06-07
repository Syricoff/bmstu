#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../Exception/Exception.h"

using std::cout;
using std::string;
using std::cin;

namespace SNS
{
    class Car
    {
    private:
        std::string brand;
        double price;
        int year;
        std::string description;
        std::string features;

    public:
        Car();
        Car(const std::string, double, int, const std::string, const std::string);

        using CarsList = std::vector<Car *>;

        void displayInfo() const;

        std::string getBrand() const;
        double getPrice() const;
        int getYear() const;
        std::string getDescription() const;
        std::string getFeatures() const;

        void setBrand(const std::string &brand);
        void setPrice(double price);
        void setYear(int year);
        void setDescription(const std::string &description);
        void setFeatures(const std::string &features);

        bool operator>(const Car &car) const;
        bool operator<(const Car &car) const;

        friend std::ostream &operator<<(std::ostream &out, const Car &car);
        friend std::istream &operator>>(std::istream &in, Car &car);
    };
} // namespace SNS
