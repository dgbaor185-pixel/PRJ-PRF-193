#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#include <vector>
#include <fstream>
#include <iostream>
#include "Room.h"
using namespace std;

class RoomManagement
{
private:
    int roomCount = 12;
    Room rooms[12];

    string getRoomType(int num)
    {
        int lastDigit = num % 10;
        if (lastDigit == 1)
            return "Normal";
        if (lastDigit == 2)
            return "VIP";
        if (lastDigit == 3)
            return "Luxury";
    }

public:
    RoomManagement() : roomCount(12)
    {
        int roomNums[12] = {101, 102, 103, 201, 202, 203, 301, 302, 303, 401, 402, 403};
        for (int i = 0; i < 12; i++)
        {
            string type = getRoomType(roomNums[i]);
            string price = (type == "Normal") ? "100$" : (type == "VIP") ? "500$"
                                                                         : "1000$";
            rooms[i] = Room(roomNums[i], type, price, false, "");
        }
    }

    void addRoom(int num)
    {
        cout << "Enter room number: ";
        cin >> num;
        cin.ignore();
        string type;
        cout << "Enter room type (Normal/VIP/Luxury): ";
        getline(cin, type);
        string price = (type == "Normal") ? "100$" : (type == "VIP") ? "500$"
                                                                     : "1000$";
        rooms[roomCount++] = Room(num, type, price, false, "");
        sortRooms();
        cout << "Room added successfully!\n";
    }

    void sortRooms()
    {
        for (int i = 0; i < roomCount - 1; i++)
        {
            for (int j = i + 1; j < roomCount; j++)
            {
                if (rooms[i].getRoomNumber() > rooms[j].getRoomNumber())
                {
                    Room temp = rooms[i];
                    rooms[i] = rooms[j];
                    rooms[j] = temp;
                }
            }
        }
    }

    void displayAllRooms()
    {
        cout << "================= ROOM LIST ================\n";
        printHeader();
        for (int i = 0; i < roomCount; i++)
            rooms[i].printInfo();
    }

    void printHeader()
    {
        cout << left << setw(8) << "RoomNumber"
             << setw(12) << "Type"
             << setw(10) << "Price"
             << setw(10) << "Status"
             << setw(12) << "Name" << endl;
        cout << "-----------------------------------------------------\n";
    }

    void editRoom(int num, string newType, string newPrice)
    {
        for (int i = 0; i < roomCount; i++)
        {
            if (rooms[i].getRoomNumber() == num)
            {
                rooms[i].setRoomType(newType);
                rooms[i].setPrice(newPrice);
                cout << "Room " << num << " updated.\n";
                return;
            }
        }
        cout << "Room not found.\n";
    }

    void deleteRoom(int num)
    {
        bool found = false;
        for (int i = 0; i < roomCount; i++)
        {
            if (rooms[i].getRoomNumber() == num)
            {
                for (int j = i; j < roomCount - 1; j++)
                    rooms[j] = rooms[j + 1];
                roomCount--;
                i--;
                found = true;
            }
        }
        if (found)
            cout << "Room" << num << " deleted.\n";
        else
            cout << "No rooms found to delete.\n";
    }
};

#endif
