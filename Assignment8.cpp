/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim:  Design and develop a context for given case study and implement an interface for Vehicles
Consider the example of vehicles like bicycle, car and bike. All Vehicles have common
functionalities such as Gear Change, Speed up and apply brakes. Make an interface and put
all these common functionalities. Bicycle, Bike, Car classes should be implemented for all
these functionalities in their own class in their own way.



I created an interface ‘Vehicle’ using pure virtual functions and implemented it in
 the classes Bicycle, Bike, and Car. Each vehicle provides its own version of gear change,
  speed control, and brake functions. Using a base class pointer, 
 A menu-driven program allows the user to select a vehicle and perform different operations
 */
 // ************    ASSIGNMENT 8     ************* 
 
#include <iostream>  
using namespace std;


// Abstract Class (Interface for Vehicles)

class Vehicle {
public:
    // Pure virtual functions (common functionalities)
    virtual void changeGear(int gear) = 0;
    virtual void speedUp(int increment) = 0;
    virtual void applyBrakes(int decrement) = 0;
};


// Class: Bicycle (implements Vehicle)

class Bicycle : public Vehicle {
private:
    int speed;
    int gear;
public:
    // Constructor initializes default values
    Bicycle() {
        speed = 0;
        gear = 1;
    }

    // Function to change gear with validation
    void changeGear(int g) override {
        if (g > 0 && g <= 5)
            gear = g;
        else
            cout << "Invalid gear! Bicycle has only 1 to 5 gears.\n";
    }

    // Function to increase speed
    void speedUp(int increment) override {
        speed += increment;
    }

    // Function to apply brakes
    void applyBrakes(int decrement) override {
        if (speed - decrement < 0)
            speed = 0;
        else
            speed -= decrement;
    }

    // Function to display details
    void display() {
        cout << "Bicycle -> Gear: " << gear << ", Speed: " << speed << " km/h\n";
    }
};


// Class: Bike (implements Vehicle)

class Bike : public Vehicle {
private:
    int speed;
    int gear;
public:
    // Constructor initializes default values
    Bike() {
        speed = 0;
        gear = 1;
    }

    // Function to change gear with validation
    void changeGear(int g) override {
        if (g > 0 && g <= 6)
            gear = g;
        else
            cout << "Invalid gear! Bike has only 1 to 6 gears.\n";
    }

    // Function to increase speed
    void speedUp(int increment) override {
        speed += increment;
    }

    // Function to apply brakes
    void applyBrakes(int decrement) override {
        if (speed - decrement < 0)
            speed = 0;
        else
            speed -= decrement;
    }

    // Function to display details
    void display() {
        cout << "Bike -> Gear: " << gear << ", Speed: " << speed << " km/h\n";
    }
};


// Class: Car (implements Vehicle)

class Car : public Vehicle {
private:
    int speed;
    int gear;
public:
    // Constructor initializes default values
    Car() {
        speed = 0;
        gear = 1;
    }

    // Function to change gear with validation
    void changeGear(int g) override {
        if (g > 0 && g <= 7)
            gear = g;
        else
            cout << "Invalid gear! Car has only 1 to 7 gears.\n";
    }

    // Function to increase speed
    void speedUp(int increment) override {
        speed += increment;
    }

    // Function to apply brakes
    void applyBrakes(int decrement) override {
        if (speed - decrement < 0)
            speed = 0;
        else
            speed -= decrement;
    }

    // Function to display details
    void display() {
        cout << "Car -> Gear: " << gear << ", Speed: " << speed << " km/h\n";
    }
};


// Main Function

int main() {
    int choice;
    Vehicle* v = nullptr; // Interface pointer (used for runtime polymorphism)

    // Create objects for each vehicle
    Bicycle b;
    Bike bk;
    Car c;

    cout << "===== VEHICLE CONTROL SYSTEM =====\n";

    // Main Menu for Vehicle Selection
    do {
        cout << "\nSelect Vehicle Type:\n";
        cout << "1. Bicycle\n";
        cout << "2. Bike\n";
        cout << "3. Car\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Input validation
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice! Please select between 1 and 4.\n";
            continue;
        }

        // Assigning appropriate object to interface pointer
        switch (choice) {
            case 1: v = &b; break;
            case 2: v = &bk; break;
            case 3: v = &c; break;
            case 4: cout << "\nExiting program...\n"; return 0;
        }

        int op;
        // Submenu for operations
        do {
            cout << "\n--- Operations Menu ---\n";
            cout << "1. Change Gear\n";
            cout << "2. Speed Up\n";
            cout << "3. Apply Brakes\n";
            cout << "4. Display Details\n";
            cout << "5. Back to Vehicle Menu\n";
            cout << "Enter operation: ";
            cin >> op;

            // Validation for operations
            if (op < 1 || op > 5) {
                cout << "Invalid operation! Try again.\n";
                continue;
            }

            int val;
            switch (op) {
                case 1: // Gear change
                    cout << "Enter gear number: ";
                    cin >> val;
                    v->changeGear(val);
                    break;

                case 2: // Speed up
                    cout << "Enter speed increment: ";
                    cin >> val;
                    if (val > 0)
                        v->speedUp(val);
                    else
                        cout << "Invalid increment value!\n";
                    break;

                case 3: // Apply brakes
                    cout << "Enter brake value: ";
                    cin >> val;
                    if (val > 0)
                        v->applyBrakes(val);
                    else
                        cout << "Invalid brake value!\n";
                    break;

                case 4: // Display details
                    if (choice == 1) b.display();
                    else if (choice == 2) bk.display();
                    else if (choice == 3) c.display();
                    break;
            }
        } while (op != 5); // Return to main menu

    } while (choice != 4);

    return 0;
}
