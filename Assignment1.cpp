/** Name : Samruddhi Sunil Bate
 * Roll no: 14
 * class : CS-SEDA-B
 * Aim : Write a C++ program to implement the concept of objects, classes, constructors, destructors.   **/

  // ************    ASSIGNMENT 1    ************* 

  
#include <iostream>
#include <string>
using namespace std;

// Class definition
class Student {
private:
    string name;
    int age;

public:
    // Constructor , a special function that is automatically called when an object is created
    Student(string n, int a) {
        name = n;
        age = a;
        cout << "Constructor called for " << name << endl;
    }

    // Member function to display student details
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Destructor (called automatically when object is destroyed)
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    // Creating objects of class Student
    Student s1("Samruddhi", 19);
    Student s2("Priya", 18);

    cout << "\n--- Student Details ---\n";
    s1.display();
    s2.display();

    cout << "\nEnd of main function...\n";
    return 0;
}
