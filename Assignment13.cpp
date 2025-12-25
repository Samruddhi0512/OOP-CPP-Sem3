/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim:  Write a generic function template that sorts an array of any type using Bubble Sort or
Selection Sort.

In this program, I implemented a generic sorting system using function templates in C++. 
I created template-based Bubble Sort and Selection Sort functions that can sort arrays of integers, 
floats, or characters. The program uses user choices for selecting data type and sorting method. 
Templates allow the same sorting code to work for multiple data types without rewriting functions
 
            **/

 // ************    ASSIGNMENT 13    *************

 #include <iostream>
using namespace std;

// ------------------------Generic Bubble Sort Function Template -----------------------------------
template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // swap if current > next
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// --------------------------------- Generic Selection Sort Function Template -----------------------------
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {  // swap
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

//--------------------------- Function to Display Array -------------------------------
template <typename T>
void displayArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// -----------------------------Main Function -----------------------------------
int main() {
    int n, typeChoice, sortChoice;

    cout << "Enter number of elements in the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid size! Setting default size = 5\n";
        n = 5;
    }

    cout << "\nSelect data type of array:\n";
    cout << "1. Integer\n2. Float\n3. Character\nEnter choice: ";
    cin >> typeChoice;

    if (typeChoice < 1 || typeChoice > 3) {
        cout << "Invalid choice! Defaulting to integer.\n";
        typeChoice = 1;
    }

    cout << "\nSelect sorting algorithm:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\nEnter choice: ";
    cin >> sortChoice;
    if (sortChoice < 1 || sortChoice > 2) {
        cout << "Invalid choice! Defaulting to Bubble Sort.\n";
        sortChoice = 1;
    }

    // ------------------- Integer Array -------------------
    if (typeChoice == 1) {
        int arr[n];
        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (sortChoice == 1)
            bubbleSort(arr, n);
        else
            selectionSort(arr, n);

        cout << "\nSorted Array: ";
        displayArray(arr, n);
    }

    // ------------------- Float Array -------------------
    else if (typeChoice == 2) {
        float arr[n];
        cout << "Enter " << n << " floats:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (sortChoice == 1)
            bubbleSort(arr, n);
        else
            selectionSort(arr, n);

        cout << "\nSorted Array: ";
        displayArray(arr, n);
    }

    // ------------------- Character Array -------------------
    else if (typeChoice == 3) {
        char arr[n];
        cout << "Enter " << n << " characters:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (sortChoice == 1)
            bubbleSort(arr, n);
        else
            selectionSort(arr, n);

        cout << "\nSorted Array: ";
        displayArray(arr, n);
    }

    return 0;
}
