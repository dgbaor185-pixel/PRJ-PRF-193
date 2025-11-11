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
    bool isBooked;
    string Name;

public:
    Room()
    {
        roomNumber = 0;
        roomType = "";
        price = "";
        isBooked = false;
        Name = "";
    }
    Room(int roomNumber, string roomType, string price, bool isBooked, string Name)
        : roomNumber(roomNumber), roomType(roomType), price(price), isBooked(isBooked), Name(Name) {}
    int getRoomNumber() { return roomNumber; }
    bool getBookedStatus() { return isBooked; }
    string getPrice() { return price; }
    string getName() { return Name; }

    void setRoomNumber(int num) { roomNumber = num; }
    void setRoomType(string type) { roomType = type; }
    void setPrice(string p) { price = p; }

    void bookRoom(string newName)
    {
        isBooked = true;
        Name = newName;
    }

    void cancelBooking()
    {
        isBooked = false;
        Name = "";
    }

    void printInfo()
    {
        cout << setw(8) << roomNumber
             << setw(12) << roomType
             << setw(10) << price
             << setw(10) << (isBooked ? "Booked" : "Available")
             << setw(12) << (isBooked ? Name : "-")
             << endl;
    }
};

#endif