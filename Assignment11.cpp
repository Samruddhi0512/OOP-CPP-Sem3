/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim:  Write a program to extend Book class with dynamic memory allocation. (Use of “new”
keyword and object pointers)
 */

 // ************    ASSIGNMENT 11    *************
  

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//  Book Class Definition -
class Book {
private:
    int bookid;
    string book_name;
    string author;
    float price;

public:
    //  Default Constructor
    Book() {
        bookid = 0;
        book_name = "Unknown";
        author = "Unknown";
        price = 0.0;
    }

    //  Function to input book details with validation
    void get_details() {
        cout << "Enter Book ID: ";
        cin >> bookid;
        if (bookid <= 0) {
            cout << "Invalid ID! Setting default value (1).\n";
            bookid = 1;
        }

        cin.ignore(); // clear input buffer
        cout << "Enter Book Name: ";
        getline(cin, book_name);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Price: ";
        cin >> price;

        if (price <= 0) {
            cout << "Invalid Price! Setting default value (100).\n";
            price = 100.0;
        }
    }

    //  Function to print book details
    void print_details() {
        cout << left << setw(10) << bookid
             << setw(20) << book_name
             << setw(20) << author
             << setw(10) << price << endl;
    }

    //  Function to return price
    float get_price() {
        return price;
    }

    //  Destructor
    ~Book() {
        cout << "Destructor called for Book ID: " << bookid << endl;
    }
};

//  Main Function 
int main() {
    int n, choice;
    float total_price = 0;

    cout << "Enter Number Of Books: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number! Setting default to 1.\n";
        n = 1;
    }

    //  Dynamic memory allocation using new keyword
    Book *books = new Book[n]; // creates an array of book objects dynamically

    do {
        //  Menu using switch case
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
                //  Display all book details
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

    //  Free dynamically allocated memory
    delete[] books; // calls destructor for each book object

    return 0;
}
