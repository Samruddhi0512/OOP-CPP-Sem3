/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim: Implement a program for maintaining a database of student records using Files. Students have
Student_id,name, Roll_no, Class, marks and address. Display the data for a few students. 1.
Create Database 2. Display Database 3. Delete Records 4. Update Record 5. Search Record
 

In this program, I created a student database system using file handling. 
I used a Student class to store details and performed create, display, search, update, 
and delete operations using binary files. I used ofstream, ifstream, and fstream for handling records 
and implemented a menu-driven interface for easy use.

1. ofstream : Output File Stream (Write to File)
               Creates file
               Writes data
               Adds new records

2. ifstream : Input File Stream (Read from File)
              Reads file
              Searches records
              Displays database

3. fstream : File Stream (Read + Write Both)
             Used for updating
             Used for modifying
             Can read + write without closing the file
*/


 // ************    ASSIGNMENT 9    ************* 

#include <iostream>
#include <fstream> // for file handling
using namespace std;

// Class: Student
class Student {
private:
    int student_id, roll_no, marks;
    char name[50], address[100], sclass[10];

public:
    // Input data from user with validation
    void inputData() {
        cout << "Enter Student ID: ";
        cin >> student_id;
        while (student_id <= 0) {
            cout << "Invalid! ID must be positive. Enter again: ";
            cin >> student_id;
        }

        cout << "Enter Roll No: ";
        cin >> roll_no;
        while (roll_no <= 0) {
            cout << "Invalid! Roll No must be positive. Enter again: ";
            cin >> roll_no;
        }

        cout << "Enter Name: ";
        
        cin.getline(name, 50);

        cout << "Enter Class: ";
        cin.getline(sclass, 10);

        cout << "Enter Marks: ";
        cin >> marks;
        while (marks < 0 || marks > 100) {
            cout << "Invalid! Marks must be 0-100. Enter again: ";
            cin >> marks;
        }

        cout << "Enter Address: ";
        cin.ignore();
        cin.getline(address, 100);
    }

    // Display student details
    void displayData() {
        cout << "\nID: " << student_id;
        cout << "\nRoll No: " << roll_no;
        cout << "\nName: " << name;
        cout << "\nClass: " << sclass;
        cout << "\nMarks: " << marks;
        cout << "\nAddress: " << address << "\n";
    }

    //used for searching/updating
    int getID() { return student_id; }
};

// Function to create database
void createDatabase() {
    ofstream out("student.dat", ios::binary | ios::app);
    Student s;
    s.inputData();
    out.write((char *)&s, sizeof(s));
    out.close();
    cout << "\nRecord added successfully!\n";
}

// Function to display all records
void displayDatabase() {
    ifstream in("student.dat", ios::binary);
    Student s;
    cout << "\n--- Student Database ---\n";
    while (in.read((char *)&s, sizeof(s))) {
        s.displayData();
        cout << "--------------------------\n";
    }
    in.close();
}

// Function to search a record
void searchRecord() {
    ifstream in("student.dat", ios::binary);
    int id, found = 0;
    cout << "Enter Student ID to search: ";
    cin >> id;

    Student s;
    while (in.read((char *)&s, sizeof(s))) {
        if (s.getID() == id) {
            cout << "\nRecord Found:\n";
            s.displayData();
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "\nRecord not found!\n";
    in.close();
}

// Function to delete a record
void deleteRecord() {
    ifstream in("student.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);
    int id, found = 0;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    Student s;
    while (in.read((char *)&s, sizeof(s))) {
        if (s.getID() != id) {
            temp.write((char *)&s, sizeof(s));
        } else {
            found = 1;
        }
    }
    in.close();
    temp.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    if (found)
        cout << "\nRecord deleted successfully!\n";
    else
        cout << "\nRecord not found!\n";
}

// Function to update a record
void updateRecord() {
    fstream file("student.dat", ios::in | ios::out | ios::binary);
    int id, found = 0;
    cout << "Enter Student ID to update: ";
    cin >> id;

    Student s;
    while (file.read((char *)&s, sizeof(s))) {
        if (s.getID() == id) {
            cout << "\nEnter new details:\n";
            s.inputData();
            file.seekp(-1 * sizeof(s), ios::cur);
            file.write((char *)&s, sizeof(s));
            cout << "\nRecord updated successfully!\n";
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "\nRecord not found!\n";
    file.close();
}

// Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\n--- STUDENT DATABASE MENU ---\n";
        cout << "1. Create Database\n";
        cout << "2. Display Database\n";
        cout << "3. Search Record\n";
        cout << "4. Update Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createDatabase();
            break;
        case 2:
            displayDatabase();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            updateRecord();
            break;
        case 5:
            deleteRecord();
            break;
        case 6:
            cout << "\nExiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
