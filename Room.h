#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Room
{
private:
    int roomNumber;
    string roomType;
    string price;
    int isBooked;
    string tenantName;

public:
    Room()
    {
        roomNumber = 0;
        roomType = "";
        price = "";
        isBooked = 0;
        tenantName = "";
    }
    Room(int roomNumber, string roomType, double price, bool status, string tenantName, int peopleCount)
        : roomNumber(roomNumber), roomType(roomType), price(price), isBooked(status), tenantName(tenantName) {}
    int getRoomNumber() { return roomNumber; }
    int getBookedStatus() { return isBooked; }
    string getPrice() { return price; }

    void bookRoom(string tenant)
    {
        isBooked = 1;
        tenantName = tenant;
    }

    void printInfo()
    {
        cout << setw(12)<< roomNumber
             << setw(15) << roomType
             << setw(15) << price
             << setw(12) << (isBooked ? "Booked" : "Available")
             << setw(18) << (isBooked ? tenantName : "-")
             << endl;
    }
};

#endif