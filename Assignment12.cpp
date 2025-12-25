/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim:  Write a program to extend Book class with dynamic memory allocation. (Use of “new”
keyword and object pointers)
 */

 // ************    ASSIGNMENT 12    *************


#include <iostream>
#include <vector>
#include <cmath> // for sqrt()
using namespace std;

// Function to check prime 
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

//  Function to check palindrome 
bool isPalindrome(int n) {
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

// Main Function 
int main() {
    int n;
    cout << "Enter number of elements in the collection: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size! Setting default size = 5\n";
        n = 5;
    }

    vector<int> numbers(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int choice;
    do {
        cout << "\n------ Count Properties Menu ------\n";
        cout << "1. Count Even Numbers\n";
        cout << "2. Count Odd Numbers\n";
        cout << "3. Count Prime Numbers\n";
        cout << "4. Count Palindrome Numbers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int count = 0;
        switch (choice) {
            case 1:
                // Count even numbers
                for (int i = 0; i < n; i++) {
                    if (numbers[i] % 2 == 0)
                        count++;
                }
                cout << "Number of even numbers: " << count << endl;
                break;

            case 2:
                // Count odd numbers
                for (int i = 0; i < n; i++) {
                    if (numbers[i] % 2 != 0)
                        count++;
                }
                cout << "Number of odd numbers: " << count << endl;
                break;

            case 3:
                // Count prime numbers
                for (int i = 0; i < n; i++) {
                    if (isPrime(numbers[i]))
                        count++;
                }
                cout << "Number of prime numbers: " << count << endl;
                break;

            case 4:
                // Count palindrome numbers
                for (int i = 0; i < n; i++) {
                    if (isPalindrome(numbers[i]))
                        count++;
                }
                cout << "Number of palindrome numbers: " << count << endl;
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
