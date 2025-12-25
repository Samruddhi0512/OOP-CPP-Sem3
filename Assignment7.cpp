/**  Name  : Samruddhi Sunil Bate
 * Roll no: 14
 * class : CS-SEDA-B
 * Practical no 07
* Aim : Design a base class shape with two double type values and member functions to input the
data and compute_area() for calculating area of shape. Derive two classes: triangle and
rectangle. Make compute_area() as an abstract function and redefine this function in the
derived class to suit their requirements. Write a program that accepts dimensions of
triangle/rectangle and displays calculated area. Implement dynamic binding for given case
study.



 I created an abstract Shape class, derived Triangle and Rectangle from it, 
and used a base class pointer to calculate area using dynamic binding based on the user’s choice.

**/

 // ************    ASSIGNMENT 7    ************* 
 
#include <iostream>
using namespace std;

// ---------- Base Class ----------
class Shape {
protected:                                 // The members are accessible in derived classes but not outside the class
    double dim1, dim2;                      

public:                                             // The members are accessible outside the class
    // Function to get input values
    void getData() {
        cout << "Enter two dimensions: ";
        cin >> dim1 >> dim2;
    }

    // Pure virtual function - abstract function    It has no implementation in the base class  The derived class must override it
    virtual void compute_area() = 0;  
};

//  Derived Class: Triangle 
class Triangle : public Shape {            
public:
    void compute_area() override { 
        double area = 0.5 * dim1 * dim2;
        cout << "Area of Triangle = " << area << endl;
    }
};

//  Derived Class: Rectangle 
class Rectangle : public Shape {
public:
    void compute_area() override {
        double area = dim1 * dim2;
        cout << "Area of Rectangle = " << area << endl;
    }
};

// Main Function 
int main() {
    Shape* shapePtr;  
    Triangle t;
    Rectangle r;
    int choice;

    cout << "Choose shape:\n1. Triangle\n2. Rectangle\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        shapePtr = &t;          // Base pointer points to Triangle object
    } else {
        shapePtr = &r;          // Base pointer points to Rectangle object
    }

    shapePtr->getData();        // Call base class function
    shapePtr->compute_area();   
    return 0;
}
