#pragma once

#include <iostream>
#include <string>
#include <format>

using std::cout;
using std::string;

class HotelRoom
{
private:
    int m_uniqueId;
    string m_roomType;
    double m_pricePerNight;
    string m_checkInDate;
    string m_checkOutDate;
    unsigned int m_numGuests;
    double m_totalCost;
    string m_notes;

public:
    HotelRoom(int, string, double, string, string, int, double, string);
    void displayInfo() const;    
    int getId() const;
    string getRoomType() const;
    double getPricePerNight() const;
    string getCheckInDate() const;
    string getCheckOutDate() const;
    unsigned int getNumGuests() const;
    double getTotalCost() const;
    string getNotes() const;
};