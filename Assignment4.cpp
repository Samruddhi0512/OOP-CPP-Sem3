/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim: Design a class ‘Complex’ with data members for real and imaginary part. Provide default and
Parameterized constructors. Write a program to perform arithmetic operations of two
complex numbers. **/

// ************    ASSIGNMENT 4   ************* 

#include <iostream>
using namespace std;

// class creation
class Complex {
private:
    float real, imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Addition
    Complex add(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex subtract(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex multiply(Complex c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Division
    Complex divide(Complex c) {
        float denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator,
                       (imag * c.real - real * c.imag) / denominator);
    }

    // Display
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    // Function to input complex number from user
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "Enter second complex number:\n";
    c2.input();

    cout << "\nFirst complex number: "; c1.display();
    cout << "Second complex number: "; c2.display();

    Complex sum = c1.add(c2);
    Complex diff = c1.subtract(c2);
    Complex prod = c1.multiply(c2);
    Complex quot = c1.divide(c2);

    cout << "\nSum: "; sum.display();
    cout << "Difference: "; diff.display();
    cout << "Product: "; prod.display();
    cout << "Quotient: "; quot.display();

    return 0;
}
