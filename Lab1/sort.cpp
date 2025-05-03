#include <iostream>
#include "sorting.h"

void print_array(const int*, int);

using namespace std;

int main() {
    int length;
    cout << "Please Enter the length of the array: ";
    cin >> length;

    int* arr = new int[length];  // dynamically allocate array

    cout << "Please Enter the elements: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    int choice = 0;
    cout << "\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n";
    cout << "\nPlease choose your option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\nOriginal array: ";
            print_array(arr, length);
            bubble_sort(arr, length);
            cout << "Sorted array: ";
            print_array(arr, length);
            break;

        case 2:
            cout << "\nOriginal array: ";
            print_array(arr, length);
            selection_sort(arr, length);
            cout << "Sorted array: ";
            print_array(arr, length);
            break;

        case 3:
            cout << "\nOriginal array: ";
            print_array(arr, length);
            insertion_sort(arr, length);
            cout << "Sorted array: ";
            print_array(arr, length);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "\nInvalid option! Please try again.\n";
    }

    delete[] arr;  // free the dynamically allocated array

    return 0;
}

void print_array(const int* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i];
        if (i < length - 1)
            cout << ", ";
    }
    cout << ".\n";
}
