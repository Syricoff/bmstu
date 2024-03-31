#pragma once

#include <string>
#include <iostream>

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
        Car(const std::string, double, int, const std::string, const std::string);

        void displayInfo();

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
    };
} // namespace SNS
