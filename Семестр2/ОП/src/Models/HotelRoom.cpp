#include "HotelRoom.h"

HotelRoom::HotelRoom(int id, string type, double price, string checkIn, string checkOut, int guests, double cost, string note)
{
    m_uniqueId = id;
    m_roomType = type;
    m_pricePerNight = price;
    m_checkInDate = checkIn;
    m_checkOutDate = checkOut;
    m_numGuests = guests;
    m_totalCost = cost;
    m_notes = note;
}

void HotelRoom::displayInfo() const
{
    std::cout << std::format("{:<10}{:<15}{:<15.2f}{:<15}{:<15}{:<10}{:<10.2f}{}\n",
                             m_uniqueId, m_roomType, m_pricePerNight, m_checkInDate, m_checkOutDate, m_numGuests, m_totalCost, m_notes);
}

int HotelRoom::getId() const { return m_uniqueId; };
std::string HotelRoom::getRoomType() const { return m_roomType; };
double HotelRoom::getPricePerNight() const { return m_pricePerNight; };
std::string HotelRoom::getCheckInDate() const { return m_checkInDate; };
std::string HotelRoom::getCheckOutDate() const { return m_checkOutDate; };
unsigned int HotelRoom::getNumGuests() const { return m_numGuests; };
double HotelRoom::getTotalCost() const { return m_totalCost; };
std::string HotelRoom::getNotes() const { return m_notes; };
