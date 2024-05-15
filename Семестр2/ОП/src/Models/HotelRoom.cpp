#include "HotelRoom.h"

#include <utility>

HotelRoom::HotelRoom(int id, string type, double price, string checkIn, string checkOut, int guests, double cost, string note)
{
    m_uniqueId = id;
    m_roomType = std::move(type);
    m_pricePerNight = price;
    m_checkInDate = std::move(checkIn);
    m_checkOutDate = std::move(checkOut);
    m_numGuests = guests;
    m_totalCost = cost;
    m_notes = std::move(note);
}
HotelRoom::~HotelRoom() = default;
HotelRoom::HotelRoom() = default;

int HotelRoom::getId() const { return m_uniqueId; };
string HotelRoom::getRoomType() const { return m_roomType; };
double HotelRoom::getPricePerNight() const { return m_pricePerNight; };
string HotelRoom::getCheckInDate() const { return m_checkInDate; };
string HotelRoom::getCheckOutDate() const { return m_checkOutDate; };
unsigned int HotelRoom::getNumGuests() const { return m_numGuests; };
double HotelRoom::getTotalCost() const { return m_totalCost; };
string HotelRoom::getNotes() const { return m_notes; }

void HotelRoom::setId(int uniqueId) {
    m_uniqueId = uniqueId;
}

void HotelRoom::setRoomType(const string &roomType) {
    m_roomType = roomType;
}

void HotelRoom::setPricePerNight(double pricePerNight) {
    m_pricePerNight = pricePerNight;
}

void HotelRoom::setCheckInDate(const string &checkInDate) {
    m_checkInDate = checkInDate;
}

void HotelRoom::setCheckOutDate(const string &checkOutDate) {
    m_checkOutDate = checkOutDate;
}

void HotelRoom::setNumGuests(unsigned int numGuests) {
    m_numGuests = numGuests;
}

void HotelRoom::setTotalCost(double totalCost) {
    m_totalCost = totalCost;
}

void HotelRoom::setNotes(const string &notes) {
    m_notes = notes;
}


std::istream &operator>>(std::istream& is, HotelRoom& room)
{
    int id;
    std::string roomType, checkInDate, checkOutDate, notes;
    double pricePerNight, totalCost;
    unsigned int numGuests;

    is >> id >> roomType >> pricePerNight >> checkInDate >> checkOutDate >> numGuests >> totalCost >> notes;
    room = HotelRoom(id, roomType, pricePerNight, checkInDate, checkOutDate, numGuests, totalCost, notes);
    return is;
}

std::ostream &operator<<(std::ostream &os, const HotelRoom &room) {
    os << room.m_uniqueId << " "
       << room.m_roomType << " "
       << room.m_pricePerNight << " "
       << room.m_checkInDate << " "
       << room.m_checkOutDate << " "
       << room.m_numGuests << " "
       << room.m_totalCost << " "
       << room.m_notes << " ";
    return os;
}




