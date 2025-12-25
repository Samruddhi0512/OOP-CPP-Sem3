/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim:  Implement a program to handle Arithmetic exceptions,
   Array Index Out of Bounds.
 * 
 In this program, I implemented exception handling in C++ using
  try and catch. I handled division-by-zero in arithmetic operations 
  and array index out-of-bounds errors. By using a menu-driven program, 
  the user can choose which exception to test. The program catches errors and
   displays messages without crashing
 */

 // ************    ASSIGNMENT 10    ************* 

 #include <iostream>
using namespace std;

int main() {
    int choice;
    
    do {
        cout << "\nException Handling Menu \n";
        cout << "1. Handle Arithmetic Exception (Division)\n";
        cout << "2. Handle Array Index Out of Bounds\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Arithmetic Exception Handling
                int num, den;
                cout << "\nEnter numerator: ";
                cin >> num;
                cout << "Enter denominator: ";
                cin >> den;

                try {
                    // Check if denominator is zero
                    if (den == 0) {
                        throw "Division by zero error!";  // Throwing means “sending an error message.”
                    } else {
                        cout << "Result = " << (float)num / den << endl;
                    }
                }
                catch (const char* msg) {
                    cout << "Exception caught: " << msg << endl;
                }
                break;
            }

            case 2: {
                // Array Index Out of Bounds Handling
                int arr[5] = {10, 20, 30, 40, 50};
                int index;

                cout << "\nEnter array index (0 to 4): ";
                cin >> index;

                try {
                    // Check if index is within valid range
                    if (index < 0 || index >= 5) {
                        throw index; // Throwing invalid index value
                    } else {
                        cout << "Value at index " << index << " = " << arr[index] << endl;
                    }
                }
                catch (int i) {
                    cout << "Exception caught: Invalid index " << i 
                         << " (Index should be between 0 and 4)\n";
                }
                break;
            }

            case 3:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
