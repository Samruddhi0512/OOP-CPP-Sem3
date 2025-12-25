/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim: Identify commonalities and differences between Publication, Book and Magazine classes.
Title, Price, Copies are common instance variables and saleCopy is a common method. The
differences are, Bookclass has author and orderCopies(). Magazine Class has methods
orderQty, Current issue, receiveissue().Write a program to find how many copies of the given
books are ordered and display total sale of publication.
 */
// ************    ASSIGNMENT 5   *************

#include <iostream>
using namespace std;

// Base Class
class Publication {
protected:
    string title;
    float price;
    int copies;

public:
    void getDetails() {
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Number of Copies: ";
        cin >> copies;
    }

    float saleCopy() {
        return price * copies;
    }

    void displayPublication() {
        cout << "\nTitle: " << title
             << "\nPrice: " << price
             << "\nCopies: " << copies
             << "\nTotal Sale: " << saleCopy() << endl;
    }
};

// Derived Class - Book
class Book : public Publication {
    string author;

public:
    void getBookDetails() {
        getDetails();
        cin.ignore();
        cout << "Enter Author Name: ";
        getline(cin, author);
    }

    void orderCopies() {
        int additional;
        cout << "Enter additional copies to order: ";
        cin >> additional;
        copies += additional;
    }

    void displayBook() {
        displayPublication();
        cout << "Author: " << author << endl;
    }
};

// Derived Class - Magazine
class Magazine : public Publication {
    int currentIssue;

public:
    void getMagazineDetails() {
        getDetails();
        cout << "Enter Current Issue Number: ";
        cin >> currentIssue;
    }

    void orderQty() {
        int additional;
        cout << "Enter additional copies to order: ";
        cin >> additional;
        copies += additional;
    }

    void receiveIssue() {
        currentIssue++;
    }

    void displayMagazine() {
        displayPublication();
        cout << "Current Issue: " << currentIssue << endl;
    }
};

int main() {
    // Book example
    Book b1;
    cout << "--- Enter Book Details ---\n";
    b1.getBookDetails();
    b1.orderCopies();
    b1.displayBook();

    // Magazine example
    Magazine m1;
    cout << "\n--- Enter Magazine Details ---\n";
    m1.getMagazineDetails();
    m1.orderQty();
    m1.receiveIssue();
    m1.displayMagazine();

    return 0;
}
