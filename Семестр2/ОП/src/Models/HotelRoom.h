#pragma once

#include <iostream>
#include <string>
#include <format>

using std::cout;
using std::string;

class HotelRoom
{
private:
    int m_uniqueId{};
    string m_roomType;
    double m_pricePerNight{};
    string m_checkInDate;
    string m_checkOutDate;
    unsigned int m_numGuests{};
    double m_totalCost{};
    string m_notes;

public:
    HotelRoom(int, string, double, string, string, int, double, string);
    HotelRoom();
    ~HotelRoom();

    friend std::istream &operator>>(std::istream& is, HotelRoom& room);
    friend std::ostream &operator<<(std::ostream &os, const HotelRoom &room);

    int getId() const;
    string getRoomType() const;
    double getPricePerNight() const;
    string getCheckInDate() const;
    string getCheckOutDate() const;
    unsigned int getNumGuests() const;
    double getTotalCost() const;
    string getNotes() const;

    void setId(int mUniqueId);
    void setRoomType(const string &roomType);
    void setPricePerNight(double pricePerNight);
    void setCheckInDate(const string &checkInDate);
    void setCheckOutDate(const string &checkOutDate);
    void setNumGuests(unsigned int numGuests);
    void setTotalCost(double TotalCost);
    void setNotes(const string &Notes);

};