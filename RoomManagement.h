#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#include <vector>
#include <fstream>
#include <iostream>
#include "Room.h"
using namespace std;

class RoomManager
{
private:
    vector<Room> rooms;

public:
    void addRoom()
    {
        int number;
        string type;
        string price;

        cout << "Enter room number: ";
        cin >> number;
        cin.ignore();
        cout << "Enter room type: ";
        getline(cin, type);
        cout << "Enter price: ";
        cin >> price;

        rooms.push_back(Room(number, type, price));
        cout << "Room adđe sucessfully!\n";
        
    }
     
    void sort()
    {
        int i, j, size = students.size();
        for (i = 0; i < size - 1; i++)
            for (j = i + 1; j < size; j++)
                if (students.at(i).getGpa() < students.at(j).getGpa())
                {
                    Student s = students.at(i);
                    students.at(i) = students.at(j);
                    students.at(j) = s;
                }
    }
    void displayAll()
    {
        if (students.empty())
        {
            cout << "\nDanh sach trong!\n";
            return;
        }

        printf("\n===== DANH SACH SINH VIEN =====\n\n");

        // In tiêu đề
        printf("-----------------------------------------------------------\n");
        printf("|%-12s |%-25s| %6s| %8s|\n", "ID", "Name", "Age", "GPA");
        printf("-----------------------------------------------------------\n");
        for (auto &s : students)
        {
            s.display();
        }
    }

    // Save as normal text (no CSV)
    void saveToFile(string filename)
    {
        ofstream out(filename);
        for (auto &s : students)
        {
            out << s.getId() << endl;
            out << s.getName() << endl;
            out << s.getAge() << endl;
            out << s.getGpa() << endl;
            out << "---" << endl; // separator
        }
        out.close();
    }

    // Load back
    void loadFromFile(string filename)
    {
        students.clear();
        ifstream in(filename);
        string id, name, line;
        int age;
        double gpa;

        while (true)
        {
            if (!getline(in, id))
                break;
            if (!getline(in, name))
                break;
            if (!(in >> age))
                break;
            if (!(in >> gpa))
                break;
            getline(in, line); // consume endline
            getline(in, line); // read separator line "---"
            students.push_back(Student(id, name, age, gpa));
        }
        in.close();
    }
};

#endif
