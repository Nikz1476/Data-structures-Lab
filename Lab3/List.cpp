#include <iostream>
using namespace std;

#define SIZE 5

class ListADT {
    int arr[SIZE];
    int count;

public:
    ListADT() : count(0) {}

    void insertBeginning(int val) {
        if (count == SIZE) {
            cout << "List is full!\n";
            return;
        }
        for (int i = count; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = val;
        count++;
    }

    void insertEnd(int val) {
        if (count == SIZE) {
            cout << "List is full!\n";
            return;
        }
        arr[count++] = val;
    }

    void insertPosition(int pos, int val) {
        if (count == SIZE || pos < 0 || pos > count) {
            cout << "Invalid position or list is full!\n";
            return;
        }
        for (int i = count; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = val;
        count++;
    }

    void deleteBeginning() {
        if (count == 0) {
            cout << "List is empty!\n";
            return;
        }
        for (int i = 0; i < count - 1; i++)
            arr[i] = arr[i + 1];
        count--;
    }

    void deleteEnd() {
        if (count == 0) {
            cout << "List is empty!\n";
            return;
        }
        count--;
    }

    void deletePosition(int pos) {
        if (count == 0 || pos < 0 || pos >= count) {
            cout << "Invalid position or list is empty!\n";
            return;
        }
        for (int i = pos; i < count - 1; i++)
            arr[i] = arr[i + 1];
        count--;
    }

    void search(int val) {
        for (int i = 0; i < count; i++) {
            if (arr[i] == val) {
                cout << "Element found at position " << i << "\n";
                return;
            }
        }
        cout << "Element not found!\n";
    }

    void display() {
        if (count == 0) {
            cout << "List is empty!\n";
            return;
        }
        for (int i = 0; i < count; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void rotate(int k) {
        k = k % count;  
        reverse(0, count - 1);
        reverse(0, k - 1);
        reverse(k, count - 1);
    }

    void reverse(int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
};

int main() {
    ListADT list;
    int choice, val, pos, k;

    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertEnd(val);
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                list.insertPosition(pos, val);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position: "; cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                cout << "Enter value to search: "; cin >> val;
                list.search(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Enter k (rotation steps): "; cin >> k;
                list.rotate(k);
                break;
            case 10:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 10);

    return 0;
}
