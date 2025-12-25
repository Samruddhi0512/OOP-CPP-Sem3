/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim: Write a C++ program to create a student class with details like Roll no, Name, 
 *      Marks of five subjects, percentage, class (First, Second, etc) using
 *      parameterized constructor, destructor, Display, Calculate percentage and grade.
 */
// ************    ASSIGNMENT 3   ************* 


#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[5];
    float percentage;
    string grade;

public:
    // Parameterized Constructor
    Student(int r, string n, float m[5]) {
        rollNo = r;
        name = n;
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }
        percentage = 0;
        grade = "Not Calculated";
        cout << "Constructor called for " << name << endl;
    }

    // Function to calculate percentage and grade
    void calculatePercentage() {
        float total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        percentage = total / 5;
        if (percentage >= 75) grade = "Distinction";
        else if (percentage >= 60) grade = "First Class";
        else if (percentage >= 50) grade = "Second Class";
        else if (percentage >= 40) grade = "Pass";
        else grade = "Fail";
    }

    // Function to display details
    void display() {
        cout << "\n--- Student Details ---\n";
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Class: " << grade << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    int roll, choice;
    string name;
    float m[5];
    Student* s = nullptr;
    bool created = false;

    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Create Student\n2. Calculate Percentage\n3. Display Details\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter marks of 5 subjects:\n";
            for (int i = 0; i < 5; i++) {
                cout << "Subject " << i + 1 << ": ";
                cin >> m[i];
            }
            s = new Student(roll, name, m);
            created = true;
            break;

        case 2:
            if (created) s->calculatePercentage();
            else cout << "Please create a student first!\n";
            break;

        case 3:
            if (created) s->display();
            else cout << "Please create a student first!\n";
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    delete s; // Calls destructor
    return 0;
}
