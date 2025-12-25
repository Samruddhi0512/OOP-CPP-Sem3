/**
 * Name : Samruddhi Sunil Bate
 * Roll no: 14
 * Class : CS-SEDA-B
 * Aim : Write a program to implement a class for Book details using 
 *       the concept of objects, classes, constructors, destructors 
 *       and switch case.
 */
// ************    ASSIGNMENT 2   ************* 

#include <iostream>
#include <iomanip> // for setw()
using namespace std;

// Class Definition 
class Book {
private:
    int bookid;
    string book_name;
    string author;
    float price;

public:
    //  Default constructor - called automatically when object is created
    Book() {
        bookid = 0;
        book_name = "Unknown";
        author = "Unknown";
        price = 0.0;
        cout << "Constructor called!\n";
    }

    //  Member function to input book details
    void get_details() {
        cout << "Enter Book ID: ";
        cin >> bookid;
        cin.ignore(); // clear input buffer

        cout << "Enter Book Name: ";
        getline(cin, book_name);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Price: ";
        cin >> price;
    }

    //  Member function to print book details
    void print_details() {
        cout << left << setw(10) << bookid
             << setw(20) << book_name
             << setw(20) << author
             << setw(10) << price << endl;
    }

    //  Function to return price (used to calculate total)
    float get_price() {
        return price;
    }

    //  Destructor - called automatically when object is destroyed
    ~Book() {
        cout << "Destructor called for Book ID: " << bookid << endl;
    }
};

// Main Function 
int main() {
    int n; // number of books
    cout << "Enter Number Of Books: ";
    cin >> n;

    //  Create array of objects
    Book books[n];
    float total_price = 0;
    int choice;

    // Menu using switch case
    do {
        cout << "\n------ Book Management Menu ------\n";
        cout << "1. Enter Book Details\n";
        cout << "2. Display Book Details\n";
        cout << "3. Calculate Total Price\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                //  Input details of all books
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter Details Of Book " << i + 1 << endl;
                    books[i].get_details();
                }
                break;

            case 2:
                //  Display book details
                cout << "\n";
                cout << left << setw(10) << "BookID"
                     << setw(20) << "Book Name"
                     << setw(20) << "Author"
                     << setw(10) << "Price" << endl;
                for (int i = 0; i < n; i++) {
                    books[i].print_details();
                }
                break;

            case 3:
                //  Calculate total price
                total_price = 0;
                for (int i = 0; i < n; i++) {
                    total_price += books[i].get_price();
                }
                cout << "\nTotal Price Of All Books = " << total_price << endl;
                break;

            case 4:
                cout << "\nExiting Program... Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 4); // loop until user chooses to exit

    return 0;
}
