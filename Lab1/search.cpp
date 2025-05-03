#include <iostream>
#include "sorting.h"

int linear_search(int*, int, int);
int binary_search(int*, int, int, int);
void print_array(int*, int);

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

    int key, position, choice = 0;
    while (true) {
        cout << "\n1. Linear Search\n2. Binary Search\n3. Exit\n";
        cout << "\nPlease choose your option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Please Enter the element to search: ";
                cin >> key;
                position = linear_search(arr, length, key);
                if (position == -1) {
                    cout << "\nElement " << key << " not found!!\n";
                } else {
                    cout << "\n" << key << " is at position: " << position << "\n";
                }
                break;

            case 2:
                cout << "\nSorting the array before binary search...\n";
                insertion_sort(arr, length);
                cout << "Sorted array: ";
                print_array(arr, length);
                cout << "Please Enter the element to search: ";
                cin >> key;
                position = binary_search(arr, 0, length - 1, key);  // corrected upper bound to length - 1
                if (position == -1) {
                    cout << "\nElement " << key << " not found!!\n";
                } else {
                    cout << "\n" << key << " is at position: " << position << " (in the sorted array)\n";
                }
                break;

            case 3:
                delete[] arr;  // free dynamically allocated array
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "\nInvalid option! Please try again.\n";
                break;
        }
    }

    // Clean up if loop exits unexpectedly
    delete[] arr;
    return 0;
}

int linear_search(int* arr, int length, int key) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(int* arr, int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (key > arr[mid]) {
        return binary_search(arr, mid + 1, right, key);
    } else {
        return binary_search(arr, left, mid - 1, key);
    }
}

void print_array(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i];
        if (i < length - 1)
            cout << ", ";
    }
    cout << ".\n";
}
